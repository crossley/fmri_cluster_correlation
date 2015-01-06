//
//  MyColorbarView.h
//  NeuroLens
//
//  Created by Rick Hoge on Fri Apr 25 2003.
//  Copyright (c) 2003 __MyCompanyName__. All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import "includes.h"

// Class to provide custom mouse drag support

@interface MyColorbarView : NSImageView {

  NSWindowController *controller;

  enum alignmentType colorbarAlignment;

}

-(enum alignmentType)colorbarAlignment;
-(void)setColorbarAlignment:(enum alignmentType)value;
-(NSImage*)makeColorbarForColorSpace:(enum colorSpaceType)colorSpace;
-(void)mouseDragged:(NSEvent *)theEvent;

-(NSWindowController*)controller;
-(void)setController:(NSWindowController*)value;

// Drag and drop
//-(NSDragOperation)draggingSourceOperationMaskForLocal:(BOOL)flag;

// Pasteboard stuff
-(void)copyToPasteboard:(NSPasteboard *)pboard;
-(IBAction)paste:(id)sender;
//-(IBAction)copy:(id)sender;
//-(void)pasteboard:(NSPasteboard *)sender provideDataForType:(NSString *)type;

@end
