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



void setup_scr_meteo(lv_ui *ui)
{
    //Write codes meteo
    ui->meteo = lv_obj_create(NULL);
    lv_obj_set_size(ui->meteo, 720, 1280);
    lv_obj_set_scrollbar_mode(ui->meteo, LV_SCROLLBAR_MODE_OFF);

    //Write style for meteo, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_src(ui->meteo, &_adad_720x1280, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_opa(ui->meteo, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_img_recolor_opa(ui->meteo, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_label_1
    ui->meteo_label_1 = lv_label_create(ui->meteo);
    lv_label_set_text(ui->meteo_label_1, "7°C");
    lv_label_set_long_mode(ui->meteo_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->meteo_label_1, 223, 206);
    lv_obj_set_size(ui->meteo_label_1, 267, 148);

    //Write style for meteo_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_label_1, &lv_font_montserratMedium_105, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->meteo_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_cont_1
    ui->meteo_cont_1 = lv_obj_create(ui->meteo);
    lv_obj_set_pos(ui->meteo_cont_1, 47, 528);
    lv_obj_set_size(ui->meteo_cont_1, 616, 389);
    lv_obj_set_scrollbar_mode(ui->meteo_cont_1, LV_SCROLLBAR_MODE_OFF);

    //Write style for meteo_cont_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_cont_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->meteo_cont_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->meteo_cont_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_cont_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_cont_1, 39, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_cont_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_cont_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_cont_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_img_1
    ui->meteo_img_1 = lv_img_create(ui->meteo_cont_1);
    lv_obj_add_flag(ui->meteo_img_1, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->meteo_img_1, &_soleilbg_alpha_87x79);
    lv_img_set_pivot(ui->meteo_img_1, 50,50);
    lv_img_set_angle(ui->meteo_img_1, 0);
    lv_obj_set_pos(ui->meteo_img_1, 274, 165);
    lv_obj_set_size(ui->meteo_img_1, 87, 79);

    //Write style for meteo_img_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->meteo_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->meteo_img_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_img_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->meteo_img_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_label_4
    ui->meteo_label_4 = lv_label_create(ui->meteo_cont_1);
    lv_label_set_text(ui->meteo_label_4, "After Tomorrow");
    lv_label_set_long_mode(ui->meteo_label_4, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->meteo_label_4, -41, 285);
    lv_obj_set_size(ui->meteo_label_4, 349, 32);

    //Write style for meteo_label_4, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_label_4, lv_color_hex(0xfcfcfc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_label_4, &lv_font_montserratMedium_26, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_label_4, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->meteo_label_4, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_label_4, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_label_4, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_label_5
    ui->meteo_label_5 = lv_label_create(ui->meteo_cont_1);
    lv_label_set_text(ui->meteo_label_5, "Tomorrow");
    lv_label_set_long_mode(ui->meteo_label_5, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->meteo_label_5, -54, 187);
    lv_obj_set_size(ui->meteo_label_5, 349, 32);

    //Write style for meteo_label_5, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_label_5, lv_color_hex(0xfcfcfc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_label_5, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_label_5, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->meteo_label_5, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_label_5, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_label_5, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_label_6
    ui->meteo_label_6 = lv_label_create(ui->meteo_cont_1);
    lv_label_set_text(ui->meteo_label_6, "Today");
    lv_label_set_long_mode(ui->meteo_label_6, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->meteo_label_6, -59, 102);
    lv_obj_set_size(ui->meteo_label_6, 349, 32);

    //Write style for meteo_label_6, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_label_6, lv_color_hex(0xfcfcfc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_label_6, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_label_6, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->meteo_label_6, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_label_6, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_label_6, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_img_2
    ui->meteo_img_2 = lv_img_create(ui->meteo);
    lv_obj_add_flag(ui->meteo_img_2, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->meteo_img_2, &_cloudy_alpha_71x53);
    lv_img_set_pivot(ui->meteo_img_2, 50,50);
    lv_img_set_angle(ui->meteo_img_2, 0);
    lv_obj_set_pos(ui->meteo_img_2, 328, 619);
    lv_obj_set_size(ui->meteo_img_2, 71, 53);

    //Write style for meteo_img_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->meteo_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->meteo_img_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_img_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->meteo_img_2, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_img_3
    ui->meteo_img_3 = lv_img_create(ui->meteo);
    lv_obj_add_flag(ui->meteo_img_3, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->meteo_img_3, &_rainybg_alpha_83x75);
    lv_img_set_pivot(ui->meteo_img_3, 50,50);
    lv_img_set_angle(ui->meteo_img_3, 0);
    lv_obj_set_pos(ui->meteo_img_3, 328, 794);
    lv_obj_set_size(ui->meteo_img_3, 83, 75);

    //Write style for meteo_img_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->meteo_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->meteo_img_3, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_img_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->meteo_img_3, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_label_2
    ui->meteo_label_2 = lv_label_create(ui->meteo);
    lv_label_set_text(ui->meteo_label_2, "3-day forecast");
    lv_label_set_long_mode(ui->meteo_label_2, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->meteo_label_2, 186, 551);
    lv_obj_set_size(ui->meteo_label_2, 349, 32);

    //Write style for meteo_label_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_label_2, lv_color_hex(0xfcfcfc), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_label_2, &lv_font_montserratMedium_28, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_label_2, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->meteo_label_2, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_label_2, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_label_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes meteo_bar_1
    ui->meteo_bar_1 = lv_bar_create(ui->meteo);
    lv_obj_set_style_anim_time(ui->meteo_bar_1, 1000, 0);
    lv_bar_set_mode(ui->meteo_bar_1, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->meteo_bar_1, 3, 8);
    lv_bar_set_value(ui->meteo_bar_1, 8, LV_ANIM_OFF);
    lv_obj_set_pos(ui->meteo_bar_1, 483, 639);
    lv_obj_set_size(ui->meteo_bar_1, 90, 20);

    //Write style for meteo_bar_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_1, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_1, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_bar_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for meteo_bar_1, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_1, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_1, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_1, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_1, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes meteo_bar_2
    ui->meteo_bar_2 = lv_bar_create(ui->meteo);
    lv_obj_set_style_anim_time(ui->meteo_bar_2, 1000, 0);
    lv_bar_set_mode(ui->meteo_bar_2, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->meteo_bar_2, 3, 8);
    lv_bar_set_value(ui->meteo_bar_2, 8, LV_ANIM_OFF);
    lv_obj_set_pos(ui->meteo_bar_2, 483, 730);
    lv_obj_set_size(ui->meteo_bar_2, 90, 20);

    //Write style for meteo_bar_2, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_2, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_2, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_2, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_2, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_bar_2, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for meteo_bar_2, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_2, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_2, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_2, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_2, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes meteo_bar_3
    ui->meteo_bar_3 = lv_bar_create(ui->meteo);
    lv_obj_set_style_anim_time(ui->meteo_bar_3, 1000, 0);
    lv_bar_set_mode(ui->meteo_bar_3, LV_BAR_MODE_NORMAL);
    lv_bar_set_range(ui->meteo_bar_3, 3, 8);
    lv_bar_set_value(ui->meteo_bar_3, 8, LV_ANIM_OFF);
    lv_obj_set_pos(ui->meteo_bar_3, 483, 829);
    lv_obj_set_size(ui->meteo_bar_3, 90, 20);

    //Write style for meteo_bar_3, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_3, 60, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_3, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_3, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_3, 10, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_bar_3, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for meteo_bar_3, Part: LV_PART_INDICATOR, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_bar_3, 255, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->meteo_bar_3, lv_color_hex(0x2195f6), LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->meteo_bar_3, LV_GRAD_DIR_NONE, LV_PART_INDICATOR|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_bar_3, 10, LV_PART_INDICATOR|LV_STATE_DEFAULT);

    //Write codes meteo_btn_1
    ui->meteo_btn_1 = lv_btn_create(ui->meteo);
    ui->meteo_btn_1_label = lv_label_create(ui->meteo_btn_1);
    lv_label_set_text(ui->meteo_btn_1_label, " <");
    lv_label_set_long_mode(ui->meteo_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->meteo_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->meteo_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->meteo_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->meteo_btn_1, 310, 961);
    lv_obj_set_size(ui->meteo_btn_1, 100, 50);

    //Write style for meteo_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->meteo_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->meteo_btn_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->meteo_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->meteo_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->meteo_btn_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->meteo_btn_1, 20, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->meteo_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->meteo_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->meteo_btn_1, &lv_font_montserratMedium_47, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->meteo_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->meteo_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of meteo.


    //Update current screen layout.
    lv_obj_update_layout(ui->meteo);

    //Init events for screen.
    events_init_meteo(ui);
}
