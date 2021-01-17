
#ifndef ZD_SCENE_H
#define ZD_SCENE_H

#include "zadesk.h"
#include "zAdAChar.h"

#pragma pack (push, 8)
#define FACEVER  0

#define         HEADER          'H'
#define         ENTITY          'E'
#define         EVERTEX         'V'
#define         POLYGON         'P'
#define         CONTOUR         'X'
#define         SHADER          'D'
#define         CMESH           'H'
#define         BLOCK_B         'U'
#define         BLOCK_E         'O'
#define         E_LAYER         'L'


#define         TOPBOT          0x2


#define ENT_HAS_CMESH  1
#define ENT_HAS_XFORM  2
#define ENT_HAS_XDATA  4
#define ENT_HAS_NORMAL 8
#define ENT_HAS_SUBENT 16


#define RENDER_CACHE      1

struct scn_cmesh {
    char   id;
    short  flags;
    long   next;
    short  mshtype;
    short  color;
    short  nverts;
    short  m;
    short  n;
};

struct scn_vrtc {
    char   id;
    double vert[3];
};

struct scn_pmsh {
    char   id;
    short  flags;
#if !defined(_WIN64) && !defined (_ZC64)
    long   adr1;
    long   adr2;
#else
    ZSoft::Int64  adr1;
    ZSoft::Int64  adr2;
#endif
    long   layerindex;
    short  color;
    long   truecolor;
    short  ncvrtx;
#if !defined(_WIN64) && !defined (_ZC64)
    long   mapperId;
#else
    ZSoft::Int64  mapperId;
#endif
};

struct scn_cvrt {
    char   id;
    long   index;
};

struct scn_node {
    double vertex[3];
    double normal[3];
    long left;
    long right;
};

#define CMAPSIZE 32

struct e2f_hdr {
    char id;
    short flags;
    short version;
    long nents;
    long npoly;
    long nlayers;
    unsigned long bgcolor;
    short cmaplen;
    char *cmap;
};

struct e2f_layer {
    char id;
    short layernamelen;
    ZTCHAR *lname;
};

struct e2f_ent {
    char id;
    short flags;
    short type;
#if !defined(_WIN64) && !defined (_ZC64)
    long  adr1;
    long  adr2;
#else
    ZSoft::Int64  adr1;
    ZSoft::Int64  adr2;
#endif
    long  npoly;
    long  nverts;
    short color;
    long  truecolor;
    long  layerindex;

#if !defined(_WIN64) && !defined (_ZC64)
    long  materialId;
#else
    ZSoft::Int64 materialId;
#endif
};

struct e2f_xform {
    char id;
    short flags;
    double xfmatrix[4][4];
};

extern struct e2f_hdr   e2fheader;
extern struct e2f_ent   e2fentity;
extern struct e2f_layer e2flayer;
extern struct e2f_xform e2fxform;
extern struct scn_vrtc  vrtcr;
extern struct scn_cvrt  cvrtr;
extern struct scn_pmsh  pmshr;

#ifdef RENDERDATA

typedef double dwg3dp[3];

class ZcReCallout {
    public :
      virtual void e2fHeaderData(struct e2f_hdr *hdr) { };
      virtual void e2fLayerData(struct e2f_layer *lyr) { };
      virtual void e2fBlockData(struct e2f_ent *ent,
                                struct e2f_xform *xform) { };
      virtual void e2fEntityData(struct e2f_ent *ent) { };
      virtual void e2fVertexData(dwg3dp *vertex_array) { };
      virtual void e2fNormalData(dwg3dp *normals_array) { };
      virtual void e2fMeshData(struct scn_pmsh *polymesh,
                               long **polyindex) { };

      int flag;

};
int zcreRegisterCallout(ZcReCallout * imp);

Zcad::ErrorStatus zcreEntityToFaces(zds_name ss, ZTCHAR** const name, int normal);

#endif

#pragma pack (pop)
#endif
