#ifndef _PC_GFX_H_
#define _PC_GFX_H_

#include "geom.h"

/* gfx primitive types */
#define PRIM_NEXT(p) (void*)((int)((p)->next) & ~3)
#define PRIM_SETNEXT(p,n) { \
int type; prim_struct *prim; \
prim = (prim_struct*)p; \
type = prim->type; \
prim->next = n; \
prim->type = type; \
}

typedef struct {
  union {
    void *next;
    struct {
      unsigned int type:2;
      unsigned int :30;
    };
  };
} prim_struct;

typedef struct {
  prim_struct;
  vec verts[3];
  rgb colors[3];
  fvec uvs[3];
  int texid;
  int pad;
} poly3i;

typedef struct {
  prim_struct;
  vec verts[4];
  rgb colors[4];
  fvec uvs[4];
  int texid;
  int pad;
} poly4i;

#endif /* _PC_GFX_H_ */
