/*
* Copyright 2025 NXP
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
static char phone_number[20];

static void home_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        task_meter = lv_timer_create(speed_meter_timer_cb, 225, &guider_ui);
        //home_label_digit_animation(&guider_ui);
        break;
    }
    case LV_EVENT_SCREEN_UNLOADED:
    {
        lv_timer_del(task_meter);
        break;
    }
    case LV_EVENT_GESTURE:
    {
        lv_dir_t dir = lv_indev_get_gesture_dir(lv_indev_get_act());
        switch(dir) {
        case LV_DIR_LEFT:
        {
            lv_indev_wait_release(lv_indev_get_act());
            break;
        }
        default:
            break;
        }
        break;
    }
    default:
        break;
    }
}

static void home_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.radio, guider_ui.radio_del, &guider_ui.home_del, setup_scr_radio, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_home (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->home, home_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->home_btn_1, home_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void radio_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_SCREEN_LOADED:
    {
        break;
    }
    default:
        break;
    }
}

static void radio_slider_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        int32_t slider_value = lv_slider_get_value(guider_ui.radio_slider_1);
        lv_span_t * fre_span = lv_spangroup_get_child(guider_ui.radio_spangroup_1, 0);
        float radio_value = (slider_value * 0.8) + 73.6;
        int32_t radio1 = (int)radio_value ;
        //if (fre_span == NULL) {
        // lv_label_set_text(guider_ui.radio_radio_label, "Error: fre_span is NULL\n");
        //return;
        //}
        char textbuffer[16];
        lv_snprintf(textbuffer, sizeof(textbuffer), "%d", radio1);
        lv_span_set_text(fre_span, textbuffer);

        switch(slider_value) {
        case 10:
        {
            lv_label_set_text(guider_ui.radio_radio_label, "Rock Music Radio");
        }
        break;
        case 20:
        {
            lv_label_set_text(guider_ui.radio_radio_label, "Rap Music Radio");
        }
        break;
        case 40:
        {
            lv_label_set_text(guider_ui.radio_radio_label, "HipPop Music Radio");
        }
        break;
        case 60:
        {
            lv_label_set_text(guider_ui.radio_radio_label, "R&B Music Radio");
        }
        break;
        case 80:
        {
            lv_label_set_text(guider_ui.radio_radio_label, "Classic Music Radio");
        }
        break;
        }
        break;
    }
    default:
        break;
    }
}

static void radio_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.radio_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

void events_init_radio (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->radio, radio_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->radio_slider_1, radio_slider_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->radio_btn_1, radio_btn_1_event_handler, LV_EVENT_ALL, ui);
}

static void telephone_btnm_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_VALUE_CHANGED:
    {
        lv_obj_t * obj = lv_event_get_target(e);
        uint32_t id = lv_btnmatrix_get_selected_btn(obj);
        int len = strlen(phone_number);
        if (len <= 10)
        {
            uint16_t sel_id = lv_btnmatrix_get_selected_btn(guider_ui.telephone_btnm_1);
            strcat(phone_number, lv_btnmatrix_get_btn_text(guider_ui.telephone_btnm_1, sel_id));
            lv_label_set_text(guider_ui.telephone_label_1, phone_number);
        }
        break;
    }
    default:
        break;
    }
}

static void telephone_label_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.telephone_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void telephone_btn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        ui_load_scr_animation(&guider_ui, &guider_ui.home, guider_ui.home_del, &guider_ui.telephone_del, setup_scr_home, LV_SCR_LOAD_ANIM_NONE, 200, 200, false, true);
        break;
    }
    default:
        break;
    }
}

static void telephone_imgbtn_1_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        bool calling = lv_obj_has_state(guider_ui.telephone_imgbtn_1, LV_STATE_CHECKED);
        if (calling)
        {
            lv_obj_set_style_opa(guider_ui.telephone_btnm_1, 0, 0);
            lv_obj_set_style_opa(guider_ui.telephone_btn_del, 0, 0);
            lv_obj_set_style_opa(guider_ui.telephone_label_1, 0, 0);

            lv_label_set_text(guider_ui.telephone_callnum, phone_number);
            lv_obj_clear_flag(guider_ui.telephone_callnum, LV_OBJ_FLAG_HIDDEN);
            lv_obj_clear_flag(guider_ui.telephone_calling, LV_OBJ_FLAG_HIDDEN);
        }
        else
        {
            lv_obj_set_style_opa(guider_ui.telephone_btnm_1, 255, 0);
            lv_obj_set_style_opa(guider_ui.telephone_btn_del, 255, 0);
            lv_obj_set_style_opa(guider_ui.telephone_label_1, 255, 0);

            lv_obj_add_flag(guider_ui.telephone_callnum, LV_OBJ_FLAG_HIDDEN);
            lv_obj_add_flag(guider_ui.telephone_calling, LV_OBJ_FLAG_HIDDEN);
        }
        break;
    }
    default:
        break;
    }
}

static void telephone_btn_del_event_handler (lv_event_t *e)
{
    lv_event_code_t code = lv_event_get_code(e);
    switch (code) {
    case LV_EVENT_CLICKED:
    {
        int p_len = strlen(phone_number);
        if (p_len > 0)
        {
            phone_number[p_len-1] = '\0';
            lv_label_set_text(guider_ui.telephone_label_1, phone_number);
        }
        break;
    }
    default:
        break;
    }
}

void events_init_telephone (lv_ui *ui)
{
    lv_obj_add_event_cb(ui->telephone_btnm_1, telephone_btnm_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->telephone_label_1, telephone_label_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->telephone_btn_1, telephone_btn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->telephone_imgbtn_1, telephone_imgbtn_1_event_handler, LV_EVENT_ALL, ui);
    lv_obj_add_event_cb(ui->telephone_btn_del, telephone_btn_del_event_handler, LV_EVENT_ALL, ui);
}


void events_init(lv_ui *ui)
{

}
