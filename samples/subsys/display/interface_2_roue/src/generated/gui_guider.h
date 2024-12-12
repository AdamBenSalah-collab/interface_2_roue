/*
* Copyright 2024 NXP
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
  
	lv_obj_t *Radio;
	bool Radio_del;
	lv_obj_t *Radio_cont_1;
	lv_obj_t *Radio_imgbtn_1;
	lv_obj_t *Radio_imgbtn_1_label;
	lv_obj_t *Radio_led_2;
	lv_obj_t *Radio_led_1;
	lv_obj_t *Radio_bar_1;
	lv_obj_t *Radio_digital_clock_1;
	lv_obj_t *Radio_spangroup_1;
	lv_span_t *Radio_spangroup_1_span;
	lv_obj_t *Radio_slider_1;
	lv_obj_t *Radio_label_1;
	lv_obj_t *Radio_btn_1;
	lv_obj_t *Radio_btn_1_label;
	lv_obj_t *screen;
	bool screen_del;
	lv_obj_t *screen_cont_1;
	lv_obj_t *screen_meter_1;
	lv_meter_scale_t *screen_meter_1_scale_0;
	lv_meter_indicator_t *screen_meter_1_scale_0_ndline_0;
	lv_meter_indicator_t *screen_meter_1_scale_0_arc_0;
	lv_meter_indicator_t *screen_meter_1_scale_0_arc_1;
	lv_meter_indicator_t *screen_meter_1_scale_0_arc_2;
	lv_obj_t *screen_speed_label_digit;
	lv_obj_t *screen_label_2;
	lv_obj_t *screen_label_1;
	lv_obj_t *screen_cont_2;
	lv_obj_t *screen_digital_clock_1;
	lv_obj_t *screen_imgbtn_2;
	lv_obj_t *screen_imgbtn_2_label;
	lv_obj_t *screen_led_1;
	lv_obj_t *screen_led_2;
	lv_obj_t *screen_bar_1;
	lv_obj_t *screen_img_2;
	lv_obj_t *screen_imgbtn_4;
	lv_obj_t *screen_imgbtn_4_label;
	lv_obj_t *screen_imgbtn_5;
	lv_obj_t *screen_imgbtn_5_label;
	lv_obj_t *screen_meteo;
	lv_obj_t *screen_imgbtn_6;
	lv_obj_t *screen_imgbtn_6_label;
	lv_obj_t *screen_imgbtn_7;
	lv_obj_t *screen_imgbtn_7_label;
	lv_obj_t *screen_imgbtn_9;
	lv_obj_t *screen_imgbtn_9_label;
	lv_obj_t *record;
	bool record_del;
	lv_obj_t *record_btn_1;
	lv_obj_t *record_btn_1_label;
	lv_obj_t *record_chart_board;
	lv_chart_series_t *record_chart_board_0;
	lv_obj_t *meteo;
	bool meteo_del;
	lv_obj_t *meteo_label_1;
	lv_obj_t *meteo_cont_1;
	lv_obj_t *meteo_img_1;
	lv_obj_t *meteo_label_4;
	lv_obj_t *meteo_label_5;
	lv_obj_t *meteo_label_6;
	lv_obj_t *meteo_img_2;
	lv_obj_t *meteo_img_3;
	lv_obj_t *meteo_label_2;
	lv_obj_t *meteo_bar_1;
	lv_obj_t *meteo_bar_2;
	lv_obj_t *meteo_bar_3;
	lv_obj_t *meteo_btn_1;
	lv_obj_t *meteo_btn_1_label;
	lv_obj_t *screen_1;
	bool screen_1_del;
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


void setup_scr_Radio(lv_ui *ui);
void setup_scr_screen(lv_ui *ui);
void setup_scr_record(lv_ui *ui);
void setup_scr_meteo(lv_ui *ui);
void setup_scr_screen_1(lv_ui *ui);

LV_IMG_DECLARE(_abs_720x1280);
LV_IMG_DECLARE(_saaremovebgpreview_alpha_45x32);

LV_IMG_DECLARE(_menu_radio_637x291);

LV_IMG_DECLARE(_play_301x301);

LV_IMG_DECLARE(_abs_720x1280);
LV_IMG_DECLARE(_saaremovebgpreview_alpha_45x32);
LV_IMG_DECLARE(_pngp_alpha_28x18);
LV_IMG_DECLARE(_absas_alpha_80x77);
LV_IMG_DECLARE(_ettadf_alpha_116x85);
LV_IMG_DECLARE(_ujo_alpha_88x76);
LV_IMG_DECLARE(_chartbg_alpha_100x50);
LV_IMG_DECLARE(_musica_alpha_85x67);
LV_IMG_DECLARE(_lk_alpha_107x70);

LV_IMG_DECLARE(_abs_720x1280);

LV_IMG_DECLARE(_adad_720x1280);
LV_IMG_DECLARE(_soleilbg_alpha_87x79);
LV_IMG_DECLARE(_cloudy_alpha_71x53);
LV_IMG_DECLARE(_rainybg_alpha_83x75);

LV_IMG_DECLARE(_abs_720x1280);

LV_FONT_DECLARE(lv_font_montserratMedium_12)
LV_FONT_DECLARE(lv_font_montserratMedium_26)
LV_FONT_DECLARE(lv_font_montserratMedium_16)
LV_FONT_DECLARE(lv_font_montserratMedium_27)
LV_FONT_DECLARE(lv_font_montserratMedium_22)
LV_FONT_DECLARE(lv_font_montserratMedium_47)
LV_FONT_DECLARE(lv_font_montserratMedium_23)
LV_FONT_DECLARE(lv_font_montserratMedium_28)
LV_FONT_DECLARE(lv_font_montserratMedium_46)
LV_FONT_DECLARE(lv_font_montserratMedium_105)


#ifdef __cplusplus
}
#endif
#endif
