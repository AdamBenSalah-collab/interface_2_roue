/*
* Copyright 2025 NXP
* NXP Proprietary. This software is owned or controlled by NXP and may only be used strictly in
* accordance with the applicable license terms. By expressly accepting such terms or by downloading, installing,
* activating and/or otherwise using the software, you are agreeing that you have read, and that you agree to
* comply with and are bound by, such license terms.  If you do not agree to be bound by the applicable license
* terms, then you may not retain, install, activate or otherwise use the software.
*/

#ifndef GUI_GUIDER_H
#define GUI_GUIDER_H
#ifdef __cplusplus
extern "C" {
#endif

#include "lvgl.h"

typedef struct
{
  
	lv_obj_t *home;
	bool home_del;
	lv_obj_t *home_meter_board;
	lv_meter_scale_t *home_meter_board_scale_0;
	lv_meter_indicator_t *home_meter_board_scale_0_ndline_0;
	lv_meter_indicator_t *home_meter_board_scale_0_scaleline_0;
	lv_meter_indicator_t *home_meter_board_scale_0_scaleline_1;
	lv_meter_indicator_t *home_meter_board_scale_0_scaleline_2;
	lv_obj_t *home_label_digit;
	lv_obj_t *home_label_trip_num;
	lv_obj_t *home_label_power_num;
	lv_obj_t *home_bar_battery;
	lv_obj_t *home_label_ODO_num;
	lv_obj_t *home_label_WIFI;
	lv_obj_t *home_label_BT;
	lv_obj_t *home_img_high_light;
	lv_obj_t *home_btn_1;
	lv_obj_t *home_btn_1_label;
	lv_obj_t *radio;
	bool radio_del;
	lv_obj_t *radio_slider_1;
	lv_obj_t *radio_spangroup_1;
	lv_span_t *radio_spangroup_1_span;
	lv_obj_t *radio_btn_1;
	lv_obj_t *radio_btn_1_label;
	lv_obj_t *radio_radio_label;
	lv_obj_t *telephone;
	bool telephone_del;
	lv_obj_t *telephone_btnm_1;
	lv_obj_t *telephone_label_1;
	lv_obj_t *telephone_btn_1;
	lv_obj_t *telephone_btn_1_label;
	lv_obj_t *telephone_imgbtn_1;
	lv_obj_t *telephone_imgbtn_1_label;
	lv_obj_t *telephone_btn_del;
	lv_obj_t *telephone_calling;
	lv_obj_t *telephone_callnum;
}lv_ui;

typedef void (*ui_setup_scr_t)(lv_ui * ui);

void ui_init_style(lv_style_t * style);

void ui_load_scr_animation(lv_ui *ui, lv_obj_t ** new_scr, bool new_scr_del, bool * old_scr_del, ui_setup_scr_t setup_scr,
                           lv_scr_load_anim_t anim_type, uint32_t time, uint32_t delay, bool is_clean, bool auto_del);

void ui_animation(void * var, int32_t duration, int32_t delay, int32_t start_value, int32_t end_value, lv_anim_path_cb_t path_cb,
                       uint16_t repeat_cnt, uint32_t repeat_delay, uint32_t playback_time, uint32_t playback_delay,
                       lv_anim_exec_xcb_t exec_cb, lv_anim_start_cb_t start_cb, lv_anim_ready_cb_t ready_cb, lv_anim_deleted_cb_t deleted_cb);


void init_scr_del_flag(lv_ui *ui);

void setup_ui(lv_ui *ui);


extern lv_ui guider_ui;


void setup_scr_home(lv_ui *ui);
void setup_scr_radio(lv_ui *ui);
void setup_scr_telephone(lv_ui *ui);

LV_IMG_DECLARE(_battery_bak_25x20);

LV_IMG_DECLARE(_battery_ind_25x20);
LV_IMG_DECLARE(_high_beam_alpha_42x42);

LV_IMG_DECLARE(_menu_radio_562x334);

LV_IMG_DECLARE(_play_344x344);
LV_IMG_DECLARE(_phone_card_alpha_100x50);
LV_IMG_DECLARE(_phone_card_alpha_100x50);
LV_IMG_DECLARE(_end_call_alpha_100x50);
LV_IMG_DECLARE(_end_call_alpha_100x50);
LV_IMG_DECLARE(_delete_alpha_100x100);

LV_FONT_DECLARE(lv_font_montserratMedium_15)
LV_FONT_DECLARE(lv_font_montserratMedium_18)
LV_FONT_DECLARE(lv_font_Antonio_Regular_36)
LV_FONT_DECLARE(lv_font_montserratMedium_24)
LV_FONT_DECLARE(lv_font_Antonio_Regular_48)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_54)
LV_FONT_DECLARE(lv_font_montserratMedium_38)


#ifdef __cplusplus
}
#endif
#endif
