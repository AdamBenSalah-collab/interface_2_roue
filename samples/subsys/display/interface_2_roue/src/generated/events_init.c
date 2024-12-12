/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "events_init.h"
#include <stdio.h>
#include "lvgl.h"

#if LV_USE_GUIDER_SIMULATOR && LV_USE_FREEMASTER
#include "freemaster_client.h"
#endif

#include "custom.h"
static lv_timer_t  * task_meter;



static lv_timer_t * task_chart;

static void Radio_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int32_t slider_value = lv_slider_get_value(guider_ui.Radio_slider_1);
        lv_span_t * fre_span = lv_spangroup_get_child(guider_ui.Radio_spangroup_1, 0);
        float radio_value = ((float)slider_value * 0.8) + 73.6;

        char textbuffer[6];
        lv_snprintf(textbuffer, sizeof(textbuffer), "%.1f", radio_value);
        lv_span_set_text(fre_span, textbuffer);

        switch(slider_value) {
        case 10:
        {
            lv_label_set_text(guider_ui.Radio_label_1, "Rock Music Radio");
        }
        break;
        case 20:
        {
            lv_label_set_text(guider_ui.Radio_label_1, "Rap Music Radio");
        }
        break;
        case 40:
        {
            lv_label_set_text(guider_ui.Radio_label_1, "HipPop Music Radio");
        }
        break;
        case 60:
        {
            lv_label_set_text(guider_ui.Radio_label_1, "R&B Music Radio");
        }
        break;
        case 80:
        {
            lv_label_set_text(guider_ui.Radio_label_1, "Classic Music Radio");
        }
        break;
        }
        break;
    }
    default:
        break;
    }
}

static void Radio_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.Radio_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_Radio (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->Radio_slider_1, Radio_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->Radio_btn_1, Radio_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void screen_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {


        task_meter = lv_timer_create(speed_meter_timer_cb, 100, &guider_ui);

        //lv_event_send(guider_ui.screen_cont_1, LV_EVENT_CLICKED, NULL);
        break;
    }
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        lv_timer_del(task_meter);
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_4_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.Radio, guider_ui.Radio_del, &guider_ui.screen_del, setup_scr_Radio, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_meteo_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.meteo, guider_ui.meteo_del, &guider_ui.screen_del, setup_scr_meteo, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

static void screen_imgbtn_6_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.record, guider_ui.record_del, &guider_ui.screen_del, setup_scr_record, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_screen (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->screen, screen_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_4, screen_imgbtn_4_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_meteo, screen_meteo_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->screen_imgbtn_6, screen_imgbtn_6_event_handler, LV_EVENT_ALL, ui);
}

static void record_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOAD_START:
    {
        task_chart = lv_timer_create(record_chart_timer_cb, 100, guider_ui.record_chart_board);
        break;
    }
    case LV_EVENT_SCREEN_UNLOAD_START:
    {
        lv_timer_del(task_chart);
        break;
    }
    default:
        break;
    }
}

static void record_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.record_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_record (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->record, record_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->record_btn_1, record_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void meteo_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.screen, guider_ui.screen_del, &guider_ui.meteo_del, setup_scr_screen, LV_SCR_LOAD_ANIM_OVER_LEFT, 200, 200, false, false);
        break;
    }
    default:
        break;
    }
}

void events_init_meteo (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->meteo_btn_1, meteo_btn_1_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
