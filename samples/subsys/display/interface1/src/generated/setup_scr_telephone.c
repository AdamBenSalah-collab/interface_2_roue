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



void setup_scr_telephone(lv_ui *ui)
{
    //Write codes telephone
    ui->telephone = lv_obj_create(NULL);
    lv_obj_set_size(ui->telephone, 720, 1280);
    lv_obj_set_scrollbar_mode(ui->telephone, LV_SCROLLBAR_MODE_OFF);

    //Write style for telephone, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->telephone, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->telephone, lv_color_hex(0x030303), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->telephone, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes telephone_btnm_1
    ui->telephone_btnm_1 = lv_btnmatrix_create(ui->telephone);
    static const char *telephone_btnm_1_text_map[] = {"1", "2", "3", "\n", "4", "5", "6", "\n", "7", "8", "9", "\n", ".", "0", "#", "",};
    lv_btnmatrix_set_map(ui->telephone_btnm_1, telephone_btnm_1_text_map);
    lv_obj_set_pos(ui->telephone_btnm_1, 197, 391);
    lv_obj_set_size(ui->telephone_btnm_1, 333, 364);

    //Write style for telephone_btnm_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->telephone_btnm_1, 1, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->telephone_btnm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->telephone_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->telephone_btnm_1, LV_BORDER_SIDE_FULL, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->telephone_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->telephone_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->telephone_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->telephone_btnm_1, 16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui->telephone_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui->telephone_btnm_1, 8, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_btnm_1, 4, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->telephone_btnm_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->telephone_btnm_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->telephone_btnm_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for telephone_btnm_1, Part: LV_PART_ITEMS, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->telephone_btnm_1, 1, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui->telephone_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui->telephone_btnm_1, lv_color_hex(0xc9c9c9), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_border_side(ui->telephone_btnm_1, LV_BORDER_SIDE_FULL, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->telephone_btnm_1, lv_color_hex(0xffffff), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_btnm_1, &lv_font_montserratMedium_16, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_btnm_1, 4, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->telephone_btnm_1, 255, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->telephone_btnm_1, lv_color_hex(0x2195f6), LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->telephone_btnm_1, LV_GRAD_DIR_NONE, LV_PART_ITEMS|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_btnm_1, 0, LV_PART_ITEMS|LV_STATE_DEFAULT);

    //Write codes telephone_label_1
    ui->telephone_label_1 = lv_label_create(ui->telephone);
    lv_label_set_text(ui->telephone_label_1, "<");
    lv_label_set_long_mode(ui->telephone_label_1, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->telephone_label_1, 330, 325);
    lv_obj_set_size(ui->telephone_label_1, 100, 32);

    //Write style for telephone_label_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->telephone_label_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_label_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_label_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->telephone_label_1, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->telephone_label_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_label_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes telephone_btn_1
    ui->telephone_btn_1 = lv_btn_create(ui->telephone);
    ui->telephone_btn_1_label = lv_label_create(ui->telephone_btn_1);
    lv_label_set_text(ui->telephone_btn_1_label, "<");
    lv_label_set_long_mode(ui->telephone_btn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->telephone_btn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->telephone_btn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_width(ui->telephone_btn_1_label, LV_PCT(100));
    lv_obj_set_pos(ui->telephone_btn_1, 339, 110);
    lv_obj_set_size(ui->telephone_btn_1, 100, 50);

    //Write style for telephone_btn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_bg_opa(ui->telephone_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui->telephone_btn_1, lv_color_hex(0x2195f6), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_grad_dir(ui->telephone_btn_1, LV_GRAD_DIR_NONE, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui->telephone_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_btn_1, 5, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_btn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->telephone_btn_1, lv_color_hex(0xffffff), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_btn_1, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_btn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->telephone_btn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes telephone_imgbtn_1
    ui->telephone_imgbtn_1 = lv_imgbtn_create(ui->telephone);
    lv_obj_add_flag(ui->telephone_imgbtn_1, LV_OBJ_FLAG_CHECKABLE);
    lv_imgbtn_set_src(ui->telephone_imgbtn_1, LV_IMGBTN_STATE_RELEASED, NULL, &_phone_card_alpha_100x50, NULL);
    lv_imgbtn_set_src(ui->telephone_imgbtn_1, LV_IMGBTN_STATE_PRESSED, NULL, &_phone_card_alpha_100x50, NULL);
    lv_imgbtn_set_src(ui->telephone_imgbtn_1, LV_IMGBTN_STATE_CHECKED_RELEASED, NULL, &_end_call_alpha_100x50, NULL);
    lv_imgbtn_set_src(ui->telephone_imgbtn_1, LV_IMGBTN_STATE_CHECKED_PRESSED, NULL, &_end_call_alpha_100x50, NULL);
    ui->telephone_imgbtn_1_label = lv_label_create(ui->telephone_imgbtn_1);
    lv_label_set_text(ui->telephone_imgbtn_1_label, "");
    lv_label_set_long_mode(ui->telephone_imgbtn_1_label, LV_LABEL_LONG_WRAP);
    lv_obj_align(ui->telephone_imgbtn_1_label, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_style_pad_all(ui->telephone_imgbtn_1, 0, LV_STATE_DEFAULT);
    lv_obj_set_pos(ui->telephone_imgbtn_1, 301, 833);
    lv_obj_set_size(ui->telephone_imgbtn_1, 100, 50);

    //Write style for telephone_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_text_color(ui->telephone_imgbtn_1, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->telephone_imgbtn_1, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->telephone_imgbtn_1, true, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write style for telephone_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_PRESSED.
    lv_obj_set_style_img_recolor_opa(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_img_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_color(ui->telephone_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_font(ui->telephone_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_text_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_PRESSED);
    lv_obj_set_style_shadow_width(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_PRESSED);

    //Write style for telephone_imgbtn_1, Part: LV_PART_MAIN, State: LV_STATE_CHECKED.
    lv_obj_set_style_img_recolor_opa(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_img_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_color(ui->telephone_imgbtn_1, lv_color_hex(0xFF33FF), LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_font(ui->telephone_imgbtn_1, &lv_font_montserratMedium_12, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_text_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_STATE_CHECKED);
    lv_obj_set_style_shadow_width(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_STATE_CHECKED);

    //Write style for telephone_imgbtn_1, Part: LV_PART_MAIN, State: LV_IMGBTN_STATE_RELEASED.
    lv_obj_set_style_img_recolor_opa(ui->telephone_imgbtn_1, 0, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);
    lv_obj_set_style_img_opa(ui->telephone_imgbtn_1, 255, LV_PART_MAIN|LV_IMGBTN_STATE_RELEASED);

    //Write codes telephone_btn_del
    ui->telephone_btn_del = lv_img_create(ui->telephone);
    lv_obj_add_flag(ui->telephone_btn_del, LV_OBJ_FLAG_CLICKABLE);
    lv_img_set_src(ui->telephone_btn_del, &_delete_alpha_100x100);
    lv_img_set_pivot(ui->telephone_btn_del, 50,50);
    lv_img_set_angle(ui->telephone_btn_del, 0);
    lv_obj_set_pos(ui->telephone_btn_del, 544, 248);
    lv_obj_set_size(ui->telephone_btn_del, 100, 100);

    //Write style for telephone_btn_del, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_img_recolor_opa(ui->telephone_btn_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_img_opa(ui->telephone_btn_del, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_btn_del, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_clip_corner(ui->telephone_btn_del, true, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes telephone_calling
    ui->telephone_calling = lv_label_create(ui->telephone);
    lv_label_set_text(ui->telephone_calling, "calling");
    lv_label_set_long_mode(ui->telephone_calling, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->telephone_calling, 310, 546);
    lv_obj_set_size(ui->telephone_calling, 207, 32);
    lv_obj_add_flag(ui->telephone_calling, LV_OBJ_FLAG_HIDDEN);

    //Write style for telephone_calling, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->telephone_calling, lv_color_hex(0xf7f7f7), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_calling, &lv_font_montserratMedium_38, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_calling, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->telephone_calling, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->telephone_calling, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_calling, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //Write codes telephone_callnum
    ui->telephone_callnum = lv_label_create(ui->telephone);
    lv_label_set_text(ui->telephone_callnum, "Label");
    lv_label_set_long_mode(ui->telephone_callnum, LV_LABEL_LONG_WRAP);
    lv_obj_set_pos(ui->telephone_callnum, 310, 261);
    lv_obj_set_size(ui->telephone_callnum, 100, 32);
    lv_obj_add_flag(ui->telephone_callnum, LV_OBJ_FLAG_HIDDEN);

    //Write style for telephone_callnum, Part: LV_PART_MAIN, State: LV_STATE_DEFAULT.
    lv_obj_set_style_border_width(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_color(ui->telephone_callnum, lv_color_hex(0x000000), LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui->telephone_callnum, &lv_font_montserratMedium_16, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(ui->telephone_callnum, 255, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_letter_space(ui->telephone_callnum, 2, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_text_align(ui->telephone_callnum, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);
    lv_obj_set_style_shadow_width(ui->telephone_callnum, 0, LV_PART_MAIN|LV_STATE_DEFAULT);

    //The custom code of telephone.


    //Update current screen layout.
    lv_obj_update_layout(ui->telephone);

    //Init events for screen.
    events_init_telephone(ui);
}
