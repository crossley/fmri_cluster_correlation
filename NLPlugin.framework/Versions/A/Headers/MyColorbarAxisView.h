//
//  MyColorbarView.h
//  NeuroLens
//
//  Created by Rick Hoge on Fri Apr 11 2003.
//  Copyright (c) 2003 __MyCompanyName__. All rights reserved.
//
//  This subclass of MyAxisView draws axes suitable for a colorbar

#import <AppKit/AppKit.h>
#import "MyAxisView.h"
#import "includes.h"

// @interface IAColorView : NSView {
@interface MyColorbarAxisView : MyAxisView {

  NSWindowController *controller;
  
  enum alignmentType colorbarAlignment;
  
}

-(NSWindowController*)controller;
-(void)setController:(NSWindowController*)value;

-(enum alignmentType)colorbarAligment;
-(void)setColorbarAlignment:(enum alignmentType)value;

@end
