/*
* Copyright 2023 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/


/*********************
 *      INCLUDES
 *********************/
#include <stdio.h>
#include "lvgl.h"
#include <stdlib.h>
#include "custom.h"


/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
 static lv_timer_t *task_chart = NULL;
 #define CHART1_POINTS 100
static int32_t speed = 0;
static bool is_increase = true;

static int16_t spd_chart[CHART1_POINTS] = {0};
static bool is_up = true;
/**
 * Create a demo application
 */
void record_chart_timer_cb(lv_timer_t * t)
{
    lv_obj_t * obj = t->user_data;
//task_chart = lv_timer_create(record_chart_timer_cb, 100, guider_ui.record_chart_board);
    lv_chart_series_t * ser = lv_chart_get_series_next(obj, NULL);
    lv_coord_t * ser_array = lv_chart_get_y_array(obj, ser);


    for(int i = 0; i < CHART1_POINTS - 1; i++)
    {
        spd_chart[i] = spd_chart[i+1];
        ser_array[i] = spd_chart[i];
    }

    if(spd_chart[CHART1_POINTS - 1] > 110) is_up = false;
    if(spd_chart[CHART1_POINTS - 1] < 70) is_up = true;

    if(is_up)
    {
        spd_chart[CHART1_POINTS - 1] += lv_rand(0, 5);
    }else
    {
        spd_chart[CHART1_POINTS - 1] -= lv_rand(0, 5);
    }
    ser_array[CHART1_POINTS - 1] = spd_chart[CHART1_POINTS - 1];
    lv_chart_refresh(obj);
}
typedef struct ui_text_item
{
  /* data */
  lv_obj_t *item_obj;
  lv_obj_t *item_obj_icon;
  const char *content_chinese;
  const char *content_english;
  const char *content_japanese;
  const char *content_korean;
} ui_text_item_t;

static struct ui_text_item item_array[7] = {
    [0] = {
        .item_obj = NULL,
        .item_obj_icon = NULL,
        .content_chinese = "美式咖啡",
        .content_english = "Americano",
        .content_japanese = "アメリカーノ",
        .content_korean = "아메리카노",
    },
    [1] = {
        .item_obj = NULL,
        .item_obj_icon = NULL,
        .content_chinese = "卡布基诺",
        .content_english = "Cappuccino",
        .content_japanese = "カプチーノ",
        .content_korean = "카푸치노",
    },
    [2] = {.item_obj = NULL, .item_obj_icon = NULL, .content_chinese = "拿铁", .content_english = "Americano", .content_japanese = "カフェラテ", .content_korean = "라떼"},
    [3] = {
        .item_obj = NULL,
        .item_obj_icon = NULL,
        .content_chinese = "白咖啡",
        .content_english = "Flat White",
        .content_japanese = "フラットホワイト",
        .content_korean = "우유 탄 커피",
    },
    [4] = {
        .item_obj = NULL,
        .item_obj_icon = NULL,
        .content_chinese = "摩卡咖啡",
        .content_english = "Mocha",
        .content_japanese = "モカ",
        .content_korean = "모카",
    },
    [5] = {
        .item_obj = NULL,
        .item_obj_icon = NULL,
        .content_chinese = "长黑咖啡",
        .content_english = "Long Black",
        .content_japanese = "ロングブラック",
        .content_korean = "롱 블랙 커피",
    },
    [6] = {
        .item_obj = NULL,
        .content_chinese = "多语言设置",
        .content_english = "Multilingual Setting",
        .content_japanese = "多言語設定",
        .content_korean = "다국어 설정",
    }};

void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void speed_meter_timer_cb(lv_timer_t * t)
{
    lv_ui * gui = t->user_data;
   // lv_led_create(led_1) ; 

    if(speed >= 110) is_increase = false;
    if(speed <= 70) is_increase = true;

    if ( speed >= 10) { lv_led_on(guider_ui.screen_led_1);}

    lv_meter_set_indicator_value(gui->screen_meter_1, gui->screen_meter_1_scale_0_ndline_0, speed);
    lv_label_set_text_fmt(gui->screen_speed_label_digit, "%"LV_PRId32, speed);
    if(is_increase)
    {
        speed ++;
    }else
    {
        speed --;
    }
}