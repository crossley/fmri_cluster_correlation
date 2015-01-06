//
//  MyMosaicImage.h
//  NeuroLens
//
//  Created by Rick Hoge on Fri Mar 26 2004.
//  Copyright (c) 2004 __MyCompanyName__. All rights reserved.
//

#import <AppKit/AppKit.h>


@interface MyMosaicImage : NSImage {
  
  int mosaicRows;
  int mosaicColumns;
  int mosaicSlices;
  
}

-(int)mosaicRows;
-(int)mosaicColumns;
-(int)mosaicSlices;

// Init method - send to newly allocated instance
- (id)initWithSize:(NSSize)aSize mosaicRows:(int)rows mosaicColumns:(int)columns mosaicSlices:(int)slices;

@end
