/*
* Copyright 2025 NXP
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



void setup_scr_radio(lv_ui *ui)
{
    //Write codes radio
    ui->radio = lv_obj_create(NULL);
    lv_obj_set_size(ui->radio, 720, 1280);
    lv_obj_set_scrollbar_mode(ui->radio, LV_SCROLLBAR_MODE_OFF);

    //Write style for radio, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->radio, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->radio, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->radio, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes radio_slider_1
    ui->radio_slider_1 = lv_slider_create(ui->radio);
    lv_slider_set_range(ui->radio_slider_1, 0, 100);
    lv_slider_set_mode(ui->radio_slider_1, LV_SLIDER_MODE_NORMAL);
    lv_slider_set_value(ui->radio_slider_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->radio_slider_1, 84, 186);
    lv_obj_set_size(ui->radio_slider_1, 562, 334);

    //Write style for radio_slider_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->radio_slider_1, 50, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_outline_width(ui->radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->radio_slider_1, &_menu_radio_562x334, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->radio_slider_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->radio_slider_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for radio_slider_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->radio_slider_1, 0, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->radio_slider_1, 50, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write style for radio_slider_1, Part: LV_PART_KNOB, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->radio_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->radio_slider_1, &_play_344x344, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->radio_slider_1, 255, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->radio_slider_1, 0, LV_PART_KNOB|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->radio_slider_1, 50, LV_PART_KNOB|LV_STATE_DEFAULT);

    //Write codes radio_spangroup_1
    ui->radio_spangroup_1 = lv_spangroup_create(ui->radio);
    lv_spangroup_set_align(ui->radio_spangroup_1, LV_TEXT_ALIGN_LEFT);
    lv_spangroup_set_overflow(ui->radio_spangroup_1, LV_SPAN_OVERFLOW_CLIP);
    lv_spangroup_set_mode(ui->radio_spangroup_1, LV_SPAN_MODE_BREAK);
    //create span
    ui->radio_spangroup_1_span = lv_spangroup_new_span(ui->radio_spangroup_1);
    lv_span_set_text(ui->radio_spangroup_1_span, "12");
    lv_style_set_text_color(&ui->radio_spangroup_1_span->style, lv_color_hex(0xe2dada));
    lv_style_set_text_decor(&ui->radio_spangroup_1_span->style, LV_TEXT_DECOR_NONE);
    lv_style_set_text_font(&ui->radio_spangroup_1_span->style, &lv_font_montserratMedium_54);
    lv_obj_set_pos(ui->radio_spangroup_1, 315, 58);
    lv_obj_set_size(ui->radio_spangroup_1, 200, 100);

    //Write style state: LV_STATE_DEFAULT for &style_radio_spangroup_1_main_main_default
    static lv_style_t style_radio_spangroup_1_main_main_default;
    ui_init_style(&style_radio_spangroup_1_main_main_default);

    lv_style_set_border_width(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_radius(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_bg_opa(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_top(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_right(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_bottom(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_pad_left(&style_radio_spangroup_1_main_main_default, 0);
    lv_style_set_shadow_width(&style_radio_spangroup_1_main_main_default, 0);
    lv_obj_add_style(ui->radio_spangroup_1, &style_radio_spangroup_1_main_main_default, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_spangroup_refr_mode(ui->radio_spangroup_1);

    //Write codes radio_btn_1
    ui->radio_btn_1 = lv_btn_create(ui->radio);
    ui->radio_btn_1_label = lv_label_create(ui->radio_btn_1);
    lv_label_set_text(ui->radio_btn_1_label, "" LV_SYMBOL_LEFT "\n");
    lv_label_set_long_mode(ui->radio_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->radio_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->radio_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->radio_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->radio_btn_1, 303, 620);
    lv_obj_set_size(ui->radio_btn_1, 126, 93);

    //Write style for radio_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->radio_btn_1, 3, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->radio_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->radio_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->radio_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->radio_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->radio_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->radio_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->radio_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->radio_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->radio_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes radio_radio_label
    ui->radio_radio_label = lv_label_create(ui->radio);
    lv_label_set_text(ui->radio_radio_label, "Label");
    lv_label_set_long_mode(ui->radio_radio_label, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->radio_radio_label, 315, 571);
    lv_obj_set_size(ui->radio_radio_label, 100, 32);

    //Write style for radio_radio_label, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->radio_radio_label, lv_color_hex(0xfdfdfd), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->radio_radio_label, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->radio_radio_label, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->radio_radio_label, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->radio_radio_label, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->radio_radio_label, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of radio.


    //Update current screen layout.
    lv_obj_update_layout(ui->radio);

    //Init events for screen.
    events_init_radio(ui);
}
