/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: min-jo <min-jo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 18:29:14 by min-jo            #+#    #+#             */
/*   Updated: 2022/11/03 23:46:08 by min-jo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSE_H
# define PARSE_H

# include "mlx_init.h"

/*
* 30개 이하라서 5비트 쉬프트하고 시작함
*/
typedef enum e_prase
{
	PARSE_ARG_ERROR = 1 << 5,
	PARSE_ARG_FINISH,
	PARSE_ARG_SPACE,
	PARSE_ARG_NUM,

	PARSE_RT_ERROR = 1 << 6,
	PARSE_RT_FINISH,
	PARSE_RT_LINE,
	PARSE_RT_SPACE,

	PARSE_RT_AMB = 1 << 7,
	PARSE_RT_AMB_SPACE,
	PARSE_RT_AMB_NUM,
	PARSE_RT_AMB_FLOAT,
	PARSE_RT_AMB_COLOR,
	PARSE_RT_AMB_R,
	PARSE_RT_AMB_G,
	PARSE_RT_AMB_B,

	PARSE_RT_CAM = 1 << 8,
	PARSE_RT_CAM_SPACE,
	PARSE_RT_CAM_POS_X_SIGN,
	PARSE_RT_CAM_POS_X_NUM,
	PARSE_RT_CAM_POS_X_FLOAT,
	PARSE_RT_CAM_POS_Y_SIGN,
	PARSE_RT_CAM_POS_Y_NUM,
	PARSE_RT_CAM_POS_Y_FLOAT,
	PARSE_RT_CAM_POS_Z_SIGN,
	PARSE_RT_CAM_POS_Z_NUM,
	PARSE_RT_CAM_POS_Z_FLOAT,
	PARSE_RT_CAM_ORI,
	PARSE_RT_CAM_ORI_X_SIGN,
	PARSE_RT_CAM_ORI_X_NUM,
	PARSE_RT_CAM_ORI_X_FLOAT,
	PARSE_RT_CAM_ORI_Y_SIGN,
	PARSE_RT_CAM_ORI_Y_NUM,
	PARSE_RT_CAM_ORI_Y_FLOAT,
	PARSE_RT_CAM_ORI_Z_SIGN,
	PARSE_RT_CAM_ORI_Z_NUM,
	PARSE_RT_CAM_ORI_Z_FLOAT,
	PARSE_RT_CAM_FOV,
	PARSE_RT_CAM_FOV_NUM,
	PARSE_RT_CAM_FOV_FLOAT,

	PARSE_RT_LIG = 1 << 9,
	PARSE_RT_LIG_SPACE,
	PARSE_RT_LIG_POS_X_SIGN,
	PARSE_RT_LIG_POS_X_NUM,
	PARSE_RT_LIG_POS_X_FLOAT,
	PARSE_RT_LIG_POS_Y_SIGN,
	PARSE_RT_LIG_POS_Y_NUM,
	PARSE_RT_LIG_POS_Y_FLOAT,
	PARSE_RT_LIG_POS_Z_SIGN,
	PARSE_RT_LIG_POS_Z_NUM,
	PARSE_RT_LIG_POS_Z_FLOAT,
	PARSE_RT_LIG_BRI,
	PARSE_RT_LIG_BRI_NUM,
	PARSE_RT_LIG_BRI_FLOAT,
	PARSE_RT_LIG_COLOR,
	PARSE_RT_LIG_R,
	PARSE_RT_LIG_G,
	PARSE_RT_LIG_B,

	PARSE_RT_SPH = 1 << 10,
	PARSE_RT_SPH_CHAR,
	PARSE_RT_SPH_SPACE,
	PARSE_RT_SPH_POS_X_SIGN,
	PARSE_RT_SPH_POS_X_NUM,
	PARSE_RT_SPH_POS_X_FLOAT,
	PARSE_RT_SPH_POS_Y_SIGN,
	PARSE_RT_SPH_POS_Y_NUM,
	PARSE_RT_SPH_POS_Y_FLOAT,
	PARSE_RT_SPH_POS_Z_SIGN,
	PARSE_RT_SPH_POS_Z_NUM,
	PARSE_RT_SPH_POS_Z_FLOAT,
	PARSE_RT_SPH_DIA,
	PARSE_RT_SPH_DIA_NUM,
	PARSE_RT_SPH_DIA_FLOAT,
	PARSE_RT_SPH_COLOR,
	PARSE_RT_SPH_R,
	PARSE_RT_SPH_G,
	PARSE_RT_SPH_B,

	PARSE_RT_PLA = 1 << 11,
	PARSE_RT_PLA_CHAR,
	PARSE_RT_PLA_SPACE,
	PARSE_RT_PLA_POS_X_SIGN,
	PARSE_RT_PLA_POS_X_NUM,
	PARSE_RT_PLA_POS_X_FLOAT,
	PARSE_RT_PLA_POS_Y_SIGN,
	PARSE_RT_PLA_POS_Y_NUM,
	PARSE_RT_PLA_POS_Y_FLOAT,
	PARSE_RT_PLA_POS_Z_SIGN,
	PARSE_RT_PLA_POS_Z_NUM,
	PARSE_RT_PLA_POS_Z_FLOAT,
	PARSE_RT_PLA_ORI,
	PARSE_RT_PLA_ORI_X_SIGN,
	PARSE_RT_PLA_ORI_X_NUM,
	PARSE_RT_PLA_ORI_X_FLOAT,
	PARSE_RT_PLA_ORI_Y_SIGN,
	PARSE_RT_PLA_ORI_Y_NUM,
	PARSE_RT_PLA_ORI_Y_FLOAT,
	PARSE_RT_PLA_ORI_Z_SIGN,
	PARSE_RT_PLA_ORI_Z_NUM,
	PARSE_RT_PLA_ORI_Z_FLOAT,
	PARSE_RT_PLA_COLOR,
	PARSE_RT_PLA_R,
	PARSE_RT_PLA_G,
	PARSE_RT_PLA_B,

	PARSE_RT_CYL = 1 << 12,
	PARSE_RT_CYL_CHAR,
	PARSE_RT_CYL_SPACE,
	PARSE_RT_CYL_POS_X_SIGN,
	PARSE_RT_CYL_POS_X_NUM,
	PARSE_RT_CYL_POS_X_FLOAT,
	PARSE_RT_CYL_POS_Y_SIGN,
	PARSE_RT_CYL_POS_Y_NUM,
	PARSE_RT_CYL_POS_Y_FLOAT,
	PARSE_RT_CYL_POS_Z_SIGN,
	PARSE_RT_CYL_POS_Z_NUM,
	PARSE_RT_CYL_POS_Z_FLOAT,
	PARSE_RT_CYL_ORI,
	PARSE_RT_CYL_ORI_X_SIGN,
	PARSE_RT_CYL_ORI_X_NUM,
	PARSE_RT_CYL_ORI_X_FLOAT,
	PARSE_RT_CYL_ORI_Y_SIGN,
	PARSE_RT_CYL_ORI_Y_NUM,
	PARSE_RT_CYL_ORI_Y_FLOAT,
	PARSE_RT_CYL_ORI_Z_SIGN,
	PARSE_RT_CYL_ORI_Z_NUM,
	PARSE_RT_CYL_ORI_Z_FLOAT,
	PARSE_RT_CYL_DIA,
	PARSE_RT_CYL_DIA_NUM,
	PARSE_RT_CYL_DIA_FLOAT,
	PARSE_RT_CYL_HEI,
	PARSE_RT_CYL_HEI_NUM,
	PARSE_RT_CYL_HEI_FLOAT,
	PARSE_RT_CYL_COLOR,
	PARSE_RT_CYL_R,
	PARSE_RT_CYL_G,
	PARSE_RT_CYL_B,
}	t_parse;

/*
* parse_arg.c
*/
t_parse	parse_arg_space(char c, int *num);
t_parse	parse_arg_num(char c, int *num);
int		parse_arg(char *str, int *num);

/*
* parse_rt.c
*/
t_parse	get_object_state(t_mlx *mlx, char c);
t_parse	parse_rt_space(t_mlx *mlx, char c);
t_parse	parse_rt_line(t_mlx *mlx, char c);
t_parse	parse_rt_default(t_mlx *mlx, char c, t_parse state);
int		parse_rt(t_mlx *mlx, int fd);

/*
* parse_rt2.c
*/
int		check_last(t_mlx *mlx, t_parse state, char c);

/*
* parse_rt_amb.c
*/
t_parse	parse_rt_amb_space(t_mlx *mlx, char c);
t_parse	parse_rt_amb_num(t_mlx *mlx, char c);
t_parse	parse_rt_amb_float(t_mlx *mlx, char c);
t_parse	parse_rt_amb(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_amb2.c
*/
t_parse	parse_rt_amb_color(t_mlx *mlx, char c);
t_parse	parse_rt_amb_r(t_mlx *mlx, char c);
t_parse	parse_rt_amb_g(t_mlx *mlx, char c);
t_parse	parse_rt_amb_b(t_mlx *mlx, char c);

/*
* parse_rt_cam.c
*/
t_parse	parse_rt_cam5(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cam4(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cam3(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cam2(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cam(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_cam2.c
*/
t_parse	parse_rt_cam_space(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_cam3.c
*/
t_parse	parse_rt_cam_pos_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_pos_z_float(t_mlx *mlx, char c);

/*
* parse_rt_cam4.c
*/
t_parse	parse_rt_cam_ori(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_cam5.c
*/
t_parse	parse_rt_cam_ori_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_ori_z_float(t_mlx *mlx, char c);

/*
* parse_rt_cam6.c
*/
t_parse	parse_rt_cam_fov(t_mlx *mlx, char c);
t_parse	parse_rt_cam_fov_num(t_mlx *mlx, char c);
t_parse	parse_rt_cam_fov_float(t_mlx *mlx, char c);
t_parse	parse_rt_cam6(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_lig.c
*/
t_parse	parse_rt_lig5(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_lig4(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_lig3(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_lig2(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_lig(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_lig2.c
*/
t_parse	parse_rt_lig_space(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_lig3.c
*/
t_parse	parse_rt_lig_pos_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_lig_pos_z_float(t_mlx *mlx, char c);

/*
* parse_rt_lig4.c
*/
t_parse	parse_rt_lig_bri(t_mlx *mlx, char c);
t_parse	parse_rt_lig_bri_num(t_mlx *mlx, char c);
t_parse	parse_rt_lig_bri_float(t_mlx *mlx, char c);

/*
* parse_rt_lig5.c
*/
t_parse	parse_rt_lig_color(t_mlx *mlx, char c);
t_parse	parse_rt_lig_r(t_mlx *mlx, char c);
t_parse	parse_rt_lig_g(t_mlx *mlx, char c);
t_parse	parse_rt_lig_b(t_mlx *mlx, char c);

/*
* parse_rt_sph.c
*/
t_parse	parse_rt_sph5(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_sph4(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_sph3(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_sph2(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_sph(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_sph2.c
*/
t_parse	parse_rt_sph_char(char c);
t_parse	parse_rt_sph_space(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_x_float(t_mlx *mlx, char c);

/*
* parse_rt_sph3.c
*/
t_parse	parse_rt_sph_pos_y_sign(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_sph_pos_z_num(t_mlx *mlx, char c);

/*
* parse_rt_sph4.c
*/
t_parse	parse_rt_sph_pos_z_float(t_mlx *mlx, char c);
t_parse	parse_rt_sph_dia(t_mlx *mlx, char c);
t_parse	parse_rt_sph_dia_num(t_mlx *mlx, char c);
t_parse	parse_rt_sph_dia_float(t_mlx *mlx, char c);

/*
* parse_rt_sph5.c
*/
t_parse	parse_rt_sph_color(t_mlx *mlx, char c);
t_parse	parse_rt_sph_r(t_mlx *mlx, char c);
t_parse	parse_rt_sph_g(t_mlx *mlx, char c);
t_parse	parse_rt_sph_b(t_mlx *mlx, char c);

/*
* parse_rt_pla.c
*/
t_parse	parse_rt_pla5(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_pla4(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_pla3(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_pla2(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_pla(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_pla2.c
*/
t_parse	parse_rt_pla_space(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_pla3.c
*/
t_parse	parse_rt_pla_pos_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_pos_z_float(t_mlx *mlx, char c);

/*
* parse_rt_pla4.c
*/
t_parse	parse_rt_pla_ori(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_pla5.c
*/
t_parse	parse_rt_pla_ori_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_pla_ori_z_float(t_mlx *mlx, char c);

/*
* parse_rt_pla6.c
*/
t_parse	parse_rt_pla_color(t_mlx *mlx, char c);
t_parse	parse_rt_pla_r(t_mlx *mlx, char c);
t_parse	parse_rt_pla_g(t_mlx *mlx, char c);
t_parse	parse_rt_pla_b(t_mlx *mlx, char c);
t_parse	parse_rt_pla6(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_pla7.c
*/
t_parse	parse_rt_pla_char(char c);

/*
* parse_rt_cyl.c
*/
t_parse	parse_rt_cyl5(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cyl4(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cyl3(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cyl2(t_mlx *mlx, char c, t_parse state);
t_parse	parse_rt_cyl(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_cyl2.c
*/
t_parse	parse_rt_cyl_space(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_cyl3.c
*/
t_parse	parse_rt_cyl_pos_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_pos_z_float(t_mlx *mlx, char c);

/*
* parse_rt_cyl4.c
*/
t_parse	parse_rt_cyl_ori(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_x_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_x_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_x_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_y_sign(t_mlx *mlx, char c);

/*
* parse_rt_cyl5.c
*/
t_parse	parse_rt_cyl_ori_y_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_y_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_z_sign(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_z_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_ori_z_float(t_mlx *mlx, char c);

/*
* parse_rt_cyl6.c
*/
t_parse	parse_rt_cyl_dia(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_dia_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_dia_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_char(char c);
t_parse	parse_rt_cyl6(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_cyl7.c
*/
t_parse	parse_rt_cyl_hei(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_hei_num(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_hei_float(t_mlx *mlx, char c);
t_parse	parse_rt_cyl7(t_mlx *mlx, char c, t_parse state);

/*
* parse_rt_cyl8.c
*/
t_parse	parse_rt_cyl_color(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_r(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_g(t_mlx *mlx, char c);
t_parse	parse_rt_cyl_b(t_mlx *mlx, char c);
t_parse	parse_rt_cyl8(t_mlx *mlx, char c, t_parse state);

#endif
