/*
* Copyright 2024 NXP
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
#include <stdlib.h>
#include "lvgl.h"
#include "custom.h"

/*********************
 *      DEFINES
 *********************/
#define CHART1_POINTS 40
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *  STATIC VARIABLES
 **********************/
static int32_t speed = 39;
static int32_t power = 3000;
static float trip = 12.4;
static int32_t ODO = 288;
static bool is_increase = true;

extern lv_ui guider_ui;
/**
 * Create a demo application
 */

/* set the digital label and steering lamp image style. */
/*static void set_position_x(void * gui, int32_t temp)
{
    lv_obj_set_x(gui, temp);
    if(temp >= 330) {
        lv_obj_set_style_img_recolor_opa(guider_ui.home_img_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_add_flag(guider_ui.home_img_light, LV_OBJ_FLAG_HIDDEN);
        lv_obj_clear_flag(guider_ui.home_img_high_light, LV_OBJ_FLAG_HIDDEN);
        if(temp % 4 == 0) {
            lv_obj_set_style_img_recolor_opa(guider_ui.home_img_right, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            lv_obj_set_style_img_recolor_opa(guider_ui.home_img_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        }
    } else {
        lv_obj_set_style_img_recolor_opa(guider_ui.home_img_right, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_clear_flag(guider_ui.home_img_light, LV_OBJ_FLAG_HIDDEN);
        lv_obj_add_flag(guider_ui.home_img_high_light, LV_OBJ_FLAG_HIDDEN);
        if(temp % 4 == 0) {
            lv_obj_set_style_img_recolor_opa(guider_ui.home_img_left, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
        } else {
            lv_obj_set_style_img_recolor_opa(guider_ui.home_img_left, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
        }
    }
}

static void set_position_y(void * gui, int32_t temp)
{
    lv_obj_set_y(gui, temp);
}
*/
void custom_init(lv_ui *ui)
{
    /* Add your codes here */
}

void speed_meter_timer_cb(lv_timer_t * t)
{
    lv_ui * gui = t->user_data;

    if(speed >= 160) is_increase = false;
    if(speed <= 30) is_increase = true;

    lv_meter_set_indicator_value(gui->home_meter_board, gui->home_meter_board_scale_0_ndline_0, speed);
    
    lv_label_set_text_fmt(gui->home_label_digit, "%"LV_PRId32, speed);
    // update trip value
    if(trip < 200.0) trip += 0.001;
    lv_label_set_text_fmt(gui->home_label_trip_num, "%"LV_PRId32, (int)trip);
    // update power value
    lv_label_set_text_fmt(gui->home_label_power_num, "%"LV_PRId32, power + speed);
    // update ODO value
    lv_label_set_text_fmt(gui->home_label_ODO_num, "%"LV_PRId32, ODO + (int)trip);
    if(is_increase)
    {
        speed += speed / 20;
    }else
    {
        speed -= speed / 10;
    }
   /* if(speed <= 60) {
        lv_obj_set_style_bg_img_recolor(gui->home_label_digit, lv_color_hex(0x06ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(gui->home_img_moto, lv_color_hex(0xf3ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
        gui->home_meter_board_scale_0_ndline_0->type_data.needle_line.color = lv_color_hex(0x00d7fd);
    }else if (speed > 60 && speed <=120){
        lv_obj_set_style_bg_img_recolor(gui->home_label_digit, lv_color_hex(0x00a7c5), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(gui->home_img_moto, lv_color_hex(0xf3ff00), LV_PART_MAIN|LV_STATE_DEFAULT);
        gui->home_meter_board_scale_0_ndline_0->type_data.needle_line.color = lv_color_hex(0x08e4aa);
    }
    else {
        lv_obj_set_style_bg_img_recolor(gui->home_label_digit, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
        lv_obj_set_style_img_recolor(gui->home_img_moto, lv_color_hex(0xff0027), LV_PART_MAIN|LV_STATE_DEFAULT);
        gui->home_meter_board_scale_0_ndline_0->type_data.needle_line.color = lv_color_hex(0xff0027);
    }*/
}

/*void home_label_digit_animation(lv_ui *ui)
{
    lv_anim_t a, b;
    lv_anim_init(&a);
    lv_anim_set_exec_cb(&a, set_position_x);
    lv_anim_set_time(&a, 3000);
    lv_anim_set_playback_time(&a, 2000);
    lv_anim_set_delay(&a, 500);
    lv_anim_set_var(&a, ui->home_label_digit);
    lv_anim_set_values(&a, 312, 356);
    lv_anim_set_repeat_count(&a, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&a);
    lv_anim_init(&b);
    lv_anim_set_exec_cb(&b, set_position_y);
    lv_anim_set_time(&b, 4000);
    lv_anim_set_playback_time(&b, 3000);
    lv_anim_set_delay(&b, 500);
    lv_anim_set_var(&b, ui->home_label_digit);
    lv_anim_set_values(&b, 522, 550);
    lv_anim_set_repeat_count(&b, LV_ANIM_REPEAT_INFINITE);
    lv_anim_start(&b);
}*/



