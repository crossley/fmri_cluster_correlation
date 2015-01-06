//
//  NLTransform.h
//  NeuroLens
//
//  Created by Rick Hoge on 9/26/05.
//  Copyright 2005 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "MyDocument.h"
#import <NLMatrix/NLMatrix.h>

@interface NLTransform : MyDocument {

  float xcenter;
  float ycenter;
  float zcenter;
  
  float xtrans;
  float ytrans;
  float ztrans;
  
  float xrot;
  float yrot;
  float zrot;
  
  float xshear;
  float yshear;
  float zshear;

  float scale;
  float xscale;
  float yscale;
  float zscale;
  
  NLMatrix *matrix;
  
}

// Init methods

-(id)initWithXcenter:(float)x0
             ycenter:(float)y0
             zcenter:(float)z0
              xtrans:(float)dx
              ytrans:(float)dy
              ztrans:(float)dz
                xrot:(float)rx
                yrot:(float)ry
                zrot:(float)rz
              xshear:(float)shx
              yshear:(float)shy
              zshear:(float)shz
               scale:(float)sc
              xscale:(float)scx
              yscale:(float)scy
              zscale:(float)scz;

-(void)setXcenter:(float)x0
          ycenter:(float)y0
          zcenter:(float)z0
           xtrans:(float)dx
           ytrans:(float)dy
           ztrans:(float)dz
             xrot:(float)rx
             yrot:(float)ry
             zrot:(float)rz
           xshear:(float)shx
           yshear:(float)shy
           zshear:(float)shz
            scale:(float)sc
           xscale:(float)scx
           yscale:(float)scy
           zscale:(float)scz;

// Accessors

-(float)xcenter;
-(void)setXcenter:(float)value;

-(float)ycenter;
-(void)setYcenter:(float)value;

-(float)zcenter;
-(void)setZcenter:(float)value;

-(float)xtrans;
-(void)setXtrans:(float)value;

-(float)ytrans;
-(void)setYtrans:(float)value;

-(float)ztrans;
-(void)setZtrans:(float)value;

-(float)xrot;
-(void)setXrot:(float)value;

-(float)yrot;
-(void)setYrot:(float)value;

-(float)zrot;
-(void)setZrot:(float)value;

-(float)xshear;
-(void)setXshear:(float)value;

-(float)yshear;
-(void)setYshear:(float)value;

-(float)zshear;
-(void)setZshear:(float)value;

-(float)scale;
-(void)setScale:(float)value;

-(float)xscale;
-(void)setXscale:(float)value;

-(float)yscale;
-(void)setYscale:(float)value;

-(float)zscale;
-(void)setZscale:(float)value;

@end
