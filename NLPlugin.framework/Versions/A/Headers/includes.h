
// This file contains source general enough that several classes might need it

#ifndef NLINCLUDE

#define NLINCLUDE

// Enumerated types
enum DATA_TYPE {
  CHARDATA=0,
  SHORTDATA,
  INTDATA,
  FLOATDATA,
  VECTORDATA,
};

// Define enum for colorspace - defined here because we may save a preference to file
enum colorSpaceType { // this needs to match tags for popup in nib file
  GREY = 0,
  SPECTRAL,
  METAL,
  NUCLEAR,
  RED,
  GREEN,
  BLUE,
  BONE,
  COOL,
  COPPER,
  FLAG,
  HSV,
  JET,
  PINK
};

// Enum for image orientation - for now is imported into IAImageView.h
enum orientationType {
  TRANSVERSE = 0,
  SAGITTAL,
  CORONAL
};

// Enum for coordinate type
enum coordinateType {
  WORLD = 0,
  VOLUME,
  INDEX
};

// Enum for directions 
enum directionType {
  XSPACE= 0,
  YSPACE,
  ZSPACE,
  TIME
};

// Enum for directions 
enum indexType {
  ROW= 0,
  COLUMN,
  SLICE,
  FRAME
};

// Enum for colorbar orientation
enum alignmentType {
  HORIZONTAL,
  VERTICAL
};

// Enum for ROI mode
enum regionMode {
  FILL = 0,
  OUTLINE,
};

// Enum for left-right convention
enum leftRightConventionType {
  NEUROSCIENCE = 0,
  RADIOLOGICAL
};

typedef struct _Vector
{
  float x;
  float y;
  float z;
} Vector;

#endif
