
//
//  MyAxisView.h
//  NeuroLens
//
//  Created by Rick Hoge on Sat Apr 12 2003.
//  Copyright (c) 2003 __MyCompanyName__. All rights reserved.
//
//  This class provides general plot axis functionality like generation of tick label values,
//  x and y-axis labels, and a plot title.  There is support for changing the color and font used.
//
//  This class should be subclassed to determine the actual appearance of the axes.  There should be
//  one subview, which is the dataView outlet connected in Interface Builder.

#import <AppKit/AppKit.h>

@interface MyAxisView : NSView {
  
  IBOutlet NSView *dataView; // View containing the data (e.g. plot or image)
  
  IBOutlet NSTextField *dataTitle; // Outlet to title field in IB
  
  NSMutableDictionary *fontAttrs; // Font attributes
  
  float dx; // distance between bottom of dataView and top of X axis labels (and title?)
  float dy; // distance between left edge of dataView and right edge of Y axis labels

  float extraSpace; // Distance in pixels left around range of data and axis box in Y direction
  
  // Line properties
  float lineWidth;
  float minLineWidth;
  float maxLineWidth;
  NSColor *frameColor; // Also applies to text
  
}

// Given min and max values, return a set of nice round
// values that can be used as axis legends
-(NSArray *)getLabelsForMin:(float)min Max:(float)max;

-(void)plotXAxisForMin:(float)min Max:(float)max;
-(void)plotYAxisForMin:(float)min Max:(float)max;
-(void)drawXlabel:(NSString*)string;
-(void)drawYlabel:(NSString*)string;
-(void)drawTitle:(NSString*)string;

// Font control
-(IBAction)changeTextFont:(id)sender; // Method to launch font panel
-(IBAction)changeFont:(id)sender; // Action sent by font panel
-(NSFont*)font; // Provides access to font in fontAttrs
-(void)setFont:(NSFont*)font;
-(NSColor*)fontColor;
-(void)setFontColor:(NSColor*)color;

// Line properties
-(float)lineWidth;
-(void)setLineWidth:(float)value;
-(BOOL)validateLineWidth:(id*)ioValue error:(NSError**)outError;
-(float)minLineWidth;
-(void)setMinLineWidth:(float)value;
-(float)maxLineWidth;
-(void)setMaxLineWidth:(float)value;
-(NSColor*)frameColor;
-(void)setFrameColor:(NSColor*)color;
-(float)extraSpace;
-(void)setExtraSpace:(float)value;

// Drag and drop
-(NSDragOperation)draggingSourceOperationMaskForLocal:(BOOL)flag;
-(void)mouseDragged:(NSEvent *)theEvent;

// Pasteboard stuff
-(void)copyToPasteboard:(NSPasteboard *)pboard;
-(IBAction)copy:(id)sender;
-(void)pasteboard:(NSPasteboard *)sender provideDataForType:(NSString *)type;

@end
