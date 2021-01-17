

#ifndef _zdsdlg_h
#define _zdsdlg_h 1

#include "zads.h"
#include "zAdAChar.h"
#pragma pack (push, 8)

#ifndef CALLB
#define CALLB
#endif

#ifdef __ZTC__
#pragma ZTC align 1
#endif

#ifdef __cplusplus
    extern "C" {
#endif

typedef void *zds_hdlg;
typedef void *zds_htile;

typedef struct {
    zds_hdlg  dialog;
    zds_htile tile;
    ZTCHAR*     value;
    void*     client_data;
    int       reason;
    long      x, y;
} zds_callback_packet;

#define CBR_SELECT       1
#define CBR_LOST_FOCUS   2
#define CBR_DRAG         3
#define CBR_DOUBLE_CLICK 4

#ifndef _PROTEUS_H
    
    typedef void (*CLIENTFUNC) (zds_callback_packet *cpkt);
#endif 

#define NULLCB ((CLIENTFUNC)0)
#define BAD_DIALOG NULL

#define DLGCANCEL     0 
#define DLGOK         1 
#define DLGALLDONE   -1 
#define DLGSTATUS     2 

#ifndef _PROCONST_H

#define LIST_CHANGE ((short) 1) 
#define LIST_APPEND ((short) 2) 
#define LIST_NEW    ((short) 3) 

#define MODE_ENABLE   ((short) 0) 
#define MODE_DISABLE  ((short) 1) 
#define MODE_SETFOCUS ((short) 2) 
#define MODE_SETSEL   ((short) 3) 
#define MODE_FLIP     ((short) 4) 
#endif  

#ifndef _PROTEUS_H
#define MAX_TILE_STR  40
#endif

#define TILE_STR_LIMIT 2035 

int zds_load_dialog            (const ZTCHAR *dclfile, int *dcl_id);
int zds_unload_dialog          (int dcl_id);
int zds_new_dialog             (const ZTCHAR *dlgname, int dcl_id,
                                CLIENTFUNC def_callback, zds_hdlg *hdlg);
int zds_new_positioned_dialog  (const ZTCHAR *dlgname, int dcl_id,
                                CLIENTFUNC def_callback, int x, int y,
                                zds_hdlg *hdlg);
int zds_start_dialog           (zds_hdlg hdlg, int *status);
int zds_term_dialog            (void);
int zds_action_tile            (zds_hdlg hdlg, const ZTCHAR *key, CLIENTFUNC tilefunc);
int zds_done_dialog            (zds_hdlg hdlg, int status);
int zds_done_positioned_dialog (zds_hdlg hdlg, int status, int *x_result,
                                  int *y_result);
int zds_set_tile          (zds_hdlg hdlg, const ZTCHAR *key, const ZTCHAR *value);
int zds_client_data_tile  (zds_hdlg hdlg, const ZTCHAR *key, void *clientdata);
int zds_get_tile          (zds_hdlg hdlg, const ZTCHAR *key,
                           ZTCHAR *value, int maxlen);
int zds_get_attr          (zds_hdlg hdlg, const ZTCHAR *key,
                           ZTCHAR *attr, ZTCHAR *value, int len);
int zds_get_attr_string   (zds_htile tile, ZTCHAR *attr, ZTCHAR *value, int len);
int zds_start_list        (zds_hdlg hdlg, const ZTCHAR *key, short operation, short index);
int zds_add_list          (const ZTCHAR *item);
int zds_end_list          (void);
int zds_mode_tile         (zds_hdlg hdlg, const ZTCHAR *key, short mode);
int zds_dimensions_tile   (zds_hdlg hdlg, const ZTCHAR *key,
                           short *cx, short *cy);
int zds_start_image       (zds_hdlg hdlg, const ZTCHAR *key);
int zds_vector_image      (short x1, short y1, short x2, short y2, short color);
int zds_fill_image        (short x1, short y1, short x2, short y2, short color);
int zds_slide_image       (short x1, short y1, short x2, short y2,
                           const ZTCHAR *slnam);
int zds_end_image         (void);

#ifdef __cplusplus
}
#endif

#pragma pack (pop)

#endif
