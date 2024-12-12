/*
* Copyright 2024 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#include "lvgl.h"
#include <stdio.h>
#include "gui_guider.h"
#include "events_init.h"
#include "widgets_init.h"
#include "custom.h"



int Radio_digital_clock_1_min_value = 25;
int Radio_digital_clock_1_hour_value = 11;
int Radio_digital_clock_1_sec_value = 50;
char Radio_digital_clock_1_meridiem[] = "AM";
void setup_scr_Radio(lv_ui *ui)
{
    //Write codes Radio
    ui->Radio = lv_obj_create(NULL);
    lv_obj_set_size(ui->Radio, 720, 1280);
    lv_obj_set_scrollbar_mode(ui->Radio, LV_SCROLLBAR_MODE_OFF);

    //Write style for Radio, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Radio, &_abs_720x1280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Radio, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Radio, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Radio_cont_1
    ui->Radio_cont_1 = lv_obj_create(ui->Radio);
    lv_obj_set_pos(ui->Radio_cont_1, 0, 0);
    lv_obj_set_size(ui->Radio_cont_1, 720, 90);
    lv_obj_set_scrollbar_mode(ui->Radio_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for Radio_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Radio_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Radio_cont_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Radio_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Radio_cont_1, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Radio_imgbtn_1
    ui->Radio_imgbtn_1 = lv_imgbtn_create(ui->Radio_cont_1);
    lv_obj_add_flag(ui->Radio_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->Radio_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_saaremovebgpreview_alpha_45x32, NULL);
    ui->Radio_imgbtn_1_label = lv_label_create(ui->Radio_imgbtn_1);
    lv_label_set_text(ui->Radio_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->Radio_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Radio_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Radio_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->Radio_imgbtn_1, 662, 15);
    lv_obj_set_size(ui->Radio_imgbtn_1, 45, 32);

    //Write style for Radio_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->Radio_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Radio_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Radio_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->Radio_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Radio_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->Radio_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->Radio_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for Radio_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->Radio_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->Radio_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for Radio_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->Radio_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->Radio_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes Radio_led_2
    ui->Radio_led_2 = lv_led_create(ui->Radio_cont_1);
    lv_led_set_brightness(ui->Radio_led_2, 0);
    lv_led_set_color(ui->Radio_led_2, lv_color_hex(0xe10303));
    lv_obj_set_pos(ui->Radio_led_2, 355, 27);
    lv_obj_set_size(ui->Radio_led_2, 15, 15);

    //Write codes Radio_led_1
    ui->Radio_led_1 = lv_led_create(ui->Radio_cont_1);
    lv_led_set_brightness(ui->Radio_led_1, 0);
    lv_led_set_color(ui->Radio_led_1, lv_color_hex(0xe10303));
    lv_obj_set_pos(ui->Radio_led_1, 300, 27);
    lv_obj_set_size(ui->Radio_led_1, 15, 15);

    //Write codes Radio_bar_1
    ui->Radio_bar_1 = lv_bar_create(ui->Radio_cont_1);
    lv_obj_set_style_anim_time(ui->Radio_bar_1, 1000, 0);
    lv_bar_set_mode(ui->Radio_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->Radio_bar_1, 0, 100);
    lv_bar_set_value(ui->Radio_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Radio_bar_1, 34, 36);
    lv_obj_set_size(ui->Radio_bar_1, 90, 21);

    //Write style for Radio_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Radio_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Radio_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Radio_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->Radio_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->Radio_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes Radio_digital_clock_1
    static bool Radio_digital_clock_1_timer_enabled = false;
    ui->Radio_digital_clock_1 = lv_dclock_create(ui->Radio_cont_1, "11:25:50 AM");
    if (!Radio_digital_clock_1_timer_enabled) {
        lv_timer_create(Radio_digital_clock_1_timer, 1000, NULL);
        Radio_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->Radio_digital_clock_1, 475, 24);
    lv_obj_set_size(ui->Radio_digital_clock_1, 164, 63);

    //Write style for Radio_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Radio_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Radio_digital_clock_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Radio_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Radio_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Radio_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Radio_spangroup_1
    ui->Radio_spangroup_1 = lv_spangroup_create(ui->Radio);
    lv_spangroup_set_align(ui->Radio_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->Radio_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->Radio_spangroup_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->Radio_spangroup_1_span = lv_spangroup_new_span(ui->Radio_spangroup_1);
    lv_span_set_text(ui->Radio_spangroup_1_span, "104.0");
    lv_style_set_text_color(&ui->Radio_spangroup_1_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->Radio_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Radio_spangroup_1_span->style, &lv_font_montserratMedium_27);
    ui->Radio_spangroup_1_span = lv_spangroup_new_span(ui->Radio_spangroup_1);
    lv_span_set_text(ui->Radio_spangroup_1_span, "MHz");
    lv_style_set_text_color(&ui->Radio_spangroup_1_span->style, lv_color_hex(0x000000));
    lv_style_set_text_decor(&ui->Radio_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->Radio_spangroup_1_span->style, &lv_font_montserratMedium_22);
    lv_obj_set_pos(ui->Radio_spangroup_1, 240, 274);
    lv_obj_set_size(ui->Radio_spangroup_1, 443, 98);

    //Write style state: LV_STATE_DEFAULT for &style_Radio_spangroup_1_main_main_default
    static lv_style_t style_Radio_spangroup_1_main_main_default;
    ui_init_style(&style_Radio_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_Radio_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_Radio_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->Radio_spangroup_1, &style_Radio_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->Radio_spangroup_1);

    //Write codes Radio_slider_1
    ui->Radio_slider_1 = lv_slider_create(ui->Radio);
    lv_slider_set_range(ui->Radio_slider_1, 0, 90);
    lv_slider_set_mode(ui->Radio_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->Radio_slider_1, 40, LV_ANIM_OFF);
    lv_obj_set_pos(ui->Radio_slider_1, 43, 504);
    lv_obj_set_size(ui->Radio_slider_1, 637, 291);

    //Write style for Radio_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->Radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Radio_slider_1, &_menu_radio_637x291, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Radio_slider_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for Radio_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_slider_1, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for Radio_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->Radio_slider_1, &_play_301x301, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->Radio_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->Radio_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes Radio_label_1
    ui->Radio_label_1 = lv_label_create(ui->Radio);
    lv_label_set_text(ui->Radio_label_1, "");
    lv_label_set_long_mode(ui->Radio_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->Radio_label_1, 197, 315);
    lv_obj_set_size(ui->Radio_label_1, 286, 56);

    //Write style for Radio_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Radio_label_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Radio_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Radio_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->Radio_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Radio_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes Radio_btn_1
    ui->Radio_btn_1 = lv_btn_create(ui->Radio);
    ui->Radio_btn_1_label = lv_label_create(ui->Radio_btn_1);
    lv_label_set_text(ui->Radio_btn_1_label, " <");
    lv_label_set_long_mode(ui->Radio_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->Radio_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->Radio_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->Radio_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->Radio_btn_1, 303, 873);
    lv_obj_set_size(ui->Radio_btn_1, 100, 50);

    //Write style for Radio_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->Radio_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->Radio_btn_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->Radio_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->Radio_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->Radio_btn_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->Radio_btn_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->Radio_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->Radio_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->Radio_btn_1, &lv_font_montserratMedium_47, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->Radio_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->Radio_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of Radio.


    //Update current screen layout.
    lv_obj_update_layout(ui->Radio);

    //Init events for screen.
    events_init_Radio(ui);
}
