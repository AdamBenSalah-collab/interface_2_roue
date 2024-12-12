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



int screen_digital_clock_1_min_value = 25;
int screen_digital_clock_1_hour_value = 11;
int screen_digital_clock_1_sec_value = 50;
char screen_digital_clock_1_meridiem[] = "AM";
void setup_scr_screen(lv_ui *ui)
{
    //Write codes screen
    ui->screen = lv_obj_create(NULL);
    lv_obj_set_size(ui->screen, 720, 1280);
    lv_obj_set_scrollbar_mode(ui->screen, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen, lv_color_hex(0x3d516b), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->screen, &_abs_720x1280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->screen, 234, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->screen, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_1
    ui->screen_cont_1 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_1, 134, 253);
    lv_obj_set_size(ui->screen_cont_1, 453, 550);
    lv_obj_set_scrollbar_mode(ui->screen_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_1, LV_BORDER_SIDE_LEFT, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_meter_1
    ui->screen_meter_1 = lv_meter_create(ui->screen_cont_1);
    // add scale ui->screen_meter_1_scale_0
    ui->screen_meter_1_scale_0 = lv_meter_add_scale(ui->screen_meter_1);
    lv_meter_set_scale_ticks(ui->screen_meter_1, ui->screen_meter_1_scale_0, 41, 3, 10, lv_color_hex(0x000000));
    lv_meter_set_scale_major_ticks(ui->screen_meter_1, ui->screen_meter_1_scale_0, 10, 4, 30, lv_color_hex(0xfdfdfd), 20);
    lv_meter_set_scale_range(ui->screen_meter_1, ui->screen_meter_1_scale_0, 0, 120, 300, 120);

    // add arc for ui->screen_meter_1_scale_0
    ui->screen_meter_1_scale_0_arc_0 = lv_meter_add_arc(ui->screen_meter_1, ui->screen_meter_1_scale_0, 10, lv_color_hex(0x00ffff), 0);
    lv_meter_set_indicator_start_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_0, 0);
    lv_meter_set_indicator_end_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_0, 30);

    // add arc for ui->screen_meter_1_scale_0
    ui->screen_meter_1_scale_0_arc_1 = lv_meter_add_arc(ui->screen_meter_1, ui->screen_meter_1_scale_0, 10, lv_color_hex(0xf3ff00), 0);
    lv_meter_set_indicator_start_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_1, 30);
    lv_meter_set_indicator_end_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_1, 90);

    // add arc for ui->screen_meter_1_scale_0
    ui->screen_meter_1_scale_0_arc_2 = lv_meter_add_arc(ui->screen_meter_1, ui->screen_meter_1_scale_0, 10, lv_color_hex(0xff0027), 0);
    lv_meter_set_indicator_start_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_2, 90);
    lv_meter_set_indicator_end_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_arc_2, 120);

    // add needle line for ui->screen_meter_1_scale_0.
    ui->screen_meter_1_scale_0_ndline_0 = lv_meter_add_needle_line(ui->screen_meter_1, ui->screen_meter_1_scale_0, 5, lv_color_hex(0x000000), -10);
    lv_meter_set_indicator_value(ui->screen_meter_1, ui->screen_meter_1_scale_0_ndline_0, 0);
    lv_obj_set_pos(ui->screen_meter_1, 16, 50);
    lv_obj_set_size(ui->screen_meter_1, 437, 437);

    //Write style for screen_meter_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_meter_1, 100, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_meter_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_meter_1, 14, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_meter_1, Part: LV_PART_TICKS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_meter_1, lv_color_hex(0xfdfdfd), LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_meter_1, &lv_font_montserratMedium_23, LV_PART_TICKS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_meter_1, 255, LV_PART_TICKS|LV_STATE_DEFAULT);

    //Write style for screen_meter_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_meter_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_meter_1, lv_color_hex(0x000000), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_meter_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_speed_label_digit
    ui->screen_speed_label_digit = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_speed_label_digit, "0\n");
    lv_label_set_long_mode(ui->screen_speed_label_digit, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_speed_label_digit, 159, 300);
    lv_obj_set_size(ui->screen_speed_label_digit, 158, 55);

    //Write style for screen_speed_label_digit, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_speed_label_digit, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_speed_label_digit, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_speed_label_digit, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_speed_label_digit, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_speed_label_digit, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_speed_label_digit, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_2
    ui->screen_label_2 = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_label_2, "Km/h");
    lv_label_set_long_mode(ui->screen_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_2, 186, 401);
    lv_obj_set_size(ui->screen_label_2, 100, 32);

    //Write style for screen_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_2, lv_color_hex(0xfefefe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_2, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_label_1
    ui->screen_label_1 = lv_label_create(ui->screen_cont_1);
    lv_label_set_text(ui->screen_label_1, "Speed");
    lv_label_set_long_mode(ui->screen_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->screen_label_1, 189, 187);
    lv_obj_set_size(ui->screen_label_1, 100, 32);

    //Write style for screen_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_label_1, lv_color_hex(0xfefefe), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_label_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_cont_2
    ui->screen_cont_2 = lv_obj_create(ui->screen);
    lv_obj_set_pos(ui->screen_cont_2, 0, 0);
    lv_obj_set_size(ui->screen_cont_2, 720, 90);
    lv_obj_set_scrollbar_mode(ui->screen_cont_2, LV_SCROLLBAR_MODE_OFF);

    //Write style for screen_cont_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->screen_cont_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->screen_cont_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->screen_cont_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->screen_cont_2, LV_BORDER_SIDE_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_cont_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_digital_clock_1
    static bool screen_digital_clock_1_timer_enabled = false;
    ui->screen_digital_clock_1 = lv_dclock_create(ui->screen_cont_2, "11:25:50 AM");
    if (!screen_digital_clock_1_timer_enabled) {
        lv_timer_create(screen_digital_clock_1_timer, 1000, NULL);
        screen_digital_clock_1_timer_enabled = true;
    }
    lv_obj_set_pos(ui->screen_digital_clock_1, 475, 24);
    lv_obj_set_size(ui->screen_digital_clock_1, 164, 63);

    //Write style for screen_digital_clock_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_digital_clock_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_digital_clock_1, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_digital_clock_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_digital_clock_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->screen_digital_clock_1, 7, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_digital_clock_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_2
    ui->screen_imgbtn_2 = lv_imgbtn_create(ui->screen_cont_2);
    lv_obj_add_flag(ui->screen_imgbtn_2, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_2, LV_IMGBTN_STATE_RELEASED, NULL, &_saaremovebgpreview_alpha_45x32, NULL);
    ui->screen_imgbtn_2_label = lv_label_create(ui->screen_imgbtn_2);
    lv_label_set_text(ui->screen_imgbtn_2_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_2_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_2_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_2, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_2, 664, 26);
    lv_obj_set_size(ui->screen_imgbtn_2, 45, 32);

    //Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_2, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_2, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_2, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_2, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_2, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_led_1
    ui->screen_led_1 = lv_led_create(ui->screen_cont_2);
    lv_led_set_brightness(ui->screen_led_1, 0);
    lv_led_set_color(ui->screen_led_1, lv_color_hex(0xe10303));
    lv_obj_set_pos(ui->screen_led_1, 355, 27);
    lv_obj_set_size(ui->screen_led_1, 15, 15);

    //Write codes screen_led_2
    ui->screen_led_2 = lv_led_create(ui->screen_cont_2);
    lv_led_set_brightness(ui->screen_led_2, 0);
    lv_led_set_color(ui->screen_led_2, lv_color_hex(0xe10303));
    lv_obj_set_pos(ui->screen_led_2, 300, 27);
    lv_obj_set_size(ui->screen_led_2, 15, 15);

    //Write codes screen_bar_1
    ui->screen_bar_1 = lv_bar_create(ui->screen_cont_2);
    lv_obj_set_style_anim_time(ui->screen_bar_1, 1000, 0);
    lv_bar_set_mode(ui->screen_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->screen_bar_1, 0, 100);
    lv_bar_set_value(ui->screen_bar_1, 50, LV_ANIM_OFF);
    lv_obj_set_pos(ui->screen_bar_1, 19, 26);
    lv_obj_set_size(ui->screen_bar_1, 90, 21);

    //Write style for screen_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->screen_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->screen_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->screen_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes screen_img_2
    ui->screen_img_2 = lv_img_create(ui->screen);
    lv_obj_add_flag(ui->screen_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_img_2, &_pngp_alpha_28x18);
    lv_img_set_pivot(ui->screen_img_2, 50,50);
    lv_img_set_angle(ui->screen_img_2, 0);
    lv_obj_set_pos(ui->screen_img_2, 350, 52);
    lv_obj_set_size(ui->screen_img_2, 28, 18);

    //Write style for screen_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_4
    ui->screen_imgbtn_4 = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_imgbtn_4, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_4, LV_IMGBTN_STATE_RELEASED, NULL, &_absas_alpha_80x77, NULL);
    ui->screen_imgbtn_4_label = lv_label_create(ui->screen_imgbtn_4);
    lv_label_set_text(ui->screen_imgbtn_4_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_4_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_4_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_4, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_4, 142, 826);
    lv_obj_set_size(ui->screen_imgbtn_4, 80, 77);

    //Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_4, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_4, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_4, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_4, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_4, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_4, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_imgbtn_5
    ui->screen_imgbtn_5 = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_imgbtn_5, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_5, LV_IMGBTN_STATE_RELEASED, NULL, &_ettadf_alpha_116x85, NULL);
    ui->screen_imgbtn_5_label = lv_label_create(ui->screen_imgbtn_5);
    lv_label_set_text(ui->screen_imgbtn_5_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_5_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_5_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_5, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_5, 321, 822);
    lv_obj_set_size(ui->screen_imgbtn_5, 116, 85);

    //Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_5, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_5, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_5, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_5, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_5, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_5, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_meteo
    ui->screen_meteo = lv_img_create(ui->screen);
    lv_obj_add_flag(ui->screen_meteo, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->screen_meteo, &_ujo_alpha_88x76);
    lv_img_set_pivot(ui->screen_meteo, 50,50);
    lv_img_set_angle(ui->screen_meteo, 0);
    lv_obj_set_pos(ui->screen_meteo, 525, 826);
    lv_obj_set_size(ui->screen_meteo, 88, 76);

    //Write style for screen_meteo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_meteo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_meteo, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_recolor_opa(ui->screen_meteo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->screen_meteo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes screen_imgbtn_6
    ui->screen_imgbtn_6 = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_imgbtn_6, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_6, LV_IMGBTN_STATE_RELEASED, NULL, &_chartbg_alpha_100x50, NULL);
    ui->screen_imgbtn_6_label = lv_label_create(ui->screen_imgbtn_6);
    lv_label_set_text(ui->screen_imgbtn_6_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_6_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_6_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_6, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_6, 129, 952);
    lv_obj_set_size(ui->screen_imgbtn_6, 100, 50);

    //Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_6, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_6, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_6, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_6, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_6, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_6, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_imgbtn_7
    ui->screen_imgbtn_7 = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_imgbtn_7, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_7, LV_IMGBTN_STATE_RELEASED, NULL, &_musica_alpha_85x67, NULL);
    ui->screen_imgbtn_7_label = lv_label_create(ui->screen_imgbtn_7);
    lv_label_set_text(ui->screen_imgbtn_7_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_7_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_7_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_7, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_7, 334, 957);
    lv_obj_set_size(ui->screen_imgbtn_7, 85, 67);

    //Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_radius(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_7, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_7, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_7, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_7, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_7, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_7, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_7, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes screen_imgbtn_9
    ui->screen_imgbtn_9 = lv_imgbtn_create(ui->screen);
    lv_obj_add_flag(ui->screen_imgbtn_9, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->screen_imgbtn_9, LV_IMGBTN_STATE_RELEASED, NULL, &_lk_alpha_107x70, NULL);
    ui->screen_imgbtn_9_label = lv_label_create(ui->screen_imgbtn_9);
    lv_label_set_text(ui->screen_imgbtn_9_label, "");
    lv_label_set_long_mode(ui->screen_imgbtn_9_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->screen_imgbtn_9_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->screen_imgbtn_9, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->screen_imgbtn_9, 519, 957);
    lv_obj_set_size(ui->screen_imgbtn_9, 107, 70);

    //Write style for screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->screen_imgbtn_9, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->screen_imgbtn_9, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->screen_imgbtn_9, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->screen_imgbtn_9, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->screen_imgbtn_9, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for screen_imgbtn_9, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->screen_imgbtn_9, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->screen_imgbtn_9, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //The custom code of screen.


    //Update current screen layout.
    lv_obj_update_layout(ui->screen);

    //Init events for screen.
    events_init_screen(ui);
}
