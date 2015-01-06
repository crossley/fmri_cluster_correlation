//
//  MyVolumeController.h
//  NeuroLens
//
//  Created by Rick Hoge on Thu Mar 18 2004.
//  Copyright (c) 2004 __MyCompanyName__. All rights reserved.
//

// This is a custom windowController subclass - it is the "File's Owner" for the 
// main document nib for volumetric (MyVolume) datasets.
//
// This custom window controller is invoked by the MyVolume class in its makeWindowControllers method.

#import <AppKit/AppKit.h>
#import "MyVolume.h"
#import "MyMosaicImage.h"
#import "MyColorbarAxisView.h"

@interface MyVolumeController : NSWindowController {

  // View settings
  float lowerWindowLevel;
  float upperWindowLevel;
  enum colorSpaceType colorSpace;  
  float minWindowSliderValue;
  float maxWindowSliderValue;
  BOOL symmetricWindow; // Center window range on zero?
  BOOL hideOverrange; // Overrange values are opaque?
  BOOL quartzInterpolation; // Use Quartz to smooth pixel edges in images?
  NSColor *sliceBackgroundColor; // Background color for slice views
  float cursorSize; // Size of image cursor
  NSColor *cursorColor; // Size of image cursor
  BOOL cursorIsVisible; // Flag for cursor visibility
  BOOL showCursorHighlight; // Flag to show cursor highlight
  NSColor *cursorHighlightColor; // Color of cursor highlight disk
  BOOL centerCursor; // Keep cursor centered while zooming?
  int traOversampling; // Oversampling factor for transverse image
  int sagOversampling; // Oversampling factor for sagittal image
  int corOversampling; // Oversampling factor for coronal image
  MyVolumeController *overlayController; // Controller for overlay volume
  float overlayOpacity; // Opacity of overlay
  float overlayThreshold; // If abs of overlay value is less than this it's transparent
  enum directionType plotDimension; // Dimension of data to plot
  NSString *plotTitle; // Title of plot
  NSString *plotXlabel; // Label for plot X axis
  NSString *plotYlabel; // Label for plot Y axis
  BOOL includeTimeWhenSyncingCoords;

  // ROI  Settings
  BOOL computeRegionStats;
  float lowerRegionThreshold;
  float upperRegionThreshold;
  NSDictionary *regionStatistics;
  NSArray *regionSignals;
  
  // Window settings
  BOOL triplanarViewsAreVisible;
  
  // IB Outlets
  IBOutlet NSView *triplanarViews;
  IBOutlet NSSplitView *mainSplitView;
  IBOutlet NSTabView *tabView;
  IBOutlet NSTabViewItem *plotTab;
  IBOutlet NSTabViewItem *traTab;
  IBOutlet NSTabViewItem *sagTab;
  IBOutlet NSTabViewItem *corTab;
  IBOutlet NSView *plotView;
  IBOutlet NSDrawer *inspectorDrawer;
  IBOutlet MyColorbarAxisView *overlayColorbar;
  IBOutlet NSTextField *overlayDescription;
  IBOutlet NSObjectController *volumeController;
  
  // Slice images
  NSImage *traSliceImage;
  NSImage *sagSliceImage;
  NSImage *corSliceImage;
  
  MyMosaicImage *traMosaicImage;
  MyMosaicImage *sagMosaicImage;
  MyMosaicImage *corMosaicImage;
  
  NSMutableDictionary *currentCoords; // The current display coordinates
  // Note that row, column, slice, etc. are represented in this dictionary
  NSString *coordsString; // Human readable representation of current coordinates
  
  // Size of the volume
  int numRows;
  int numColumns;
  int numSlices;
  int numFrames;
  
  // External decoration support
  id plotDecorator;
  
  // Volume info support
  IBOutlet NSTableView *volumeInfoTable;
  IBOutlet NSWindow *volumeInfoSheet;

  IBOutlet NSMenu *colorSpaceMenu; // Menu for color space
  
  IBOutlet NSArrayController *demographicInfoController;
  
  // Dummy booleans for bindings
  BOOL isNo;
  BOOL isYes;
  
  // Toolbar outlets
  
  IBOutlet NSView *colorspaceItemView;
  IBOutlet NSView *levelsItemView;
  IBOutlet NSView *actionItemView;
  IBOutlet NSView *metadataItemView;
  IBOutlet NSView *overlayItemView;
  IBOutlet NSView *opacityItemView;
  IBOutlet NSView *paintValueItemView;
  IBOutlet NSView *paintModeItemView;
  
  IBOutlet NSButton *actionButton;
  
  // Inspector panel
  IBOutlet NSView *inspectorView;
  
  NSString *description;
  
}

// List of other volumes
-(NSArray*)otherVolumes;

// Custom description - used when we want to control what
// appears in bound UI elements
-(NSString*)description;
-(void)setDescription:(NSString*)value;

// View Settings
-(float)lowerWindowLevel;
-(void)setLowerWindowLevel:(float)level;
-(BOOL)validateLowerWindowLevel:(id*)ioValue error:(NSError**)outError;
-(float)upperWindowLevel;
-(void)setUpperWindowLevel:(float)level;
-(BOOL)validateUpperWindowLevel:(id*)ioValue error:(NSError**)outError;
-(void)setMinWindowSliderValue:(float)value;
-(void)setMaxWindowSliderValue:(float)value;
-(BOOL)symmetricWindow;
-(void)setSymmetricWindow:(BOOL)value;
-(BOOL)hideOverrange;
-(void)sethideOverrange:(BOOL)value;
-(BOOL)quartzInterpolation;
-(void)setQuartzInterpolation:(BOOL)value;
-(BOOL)centerCursor;
-(void)setCenterCursor:(BOOL)value;
-(NSColor*)sliceBackgroundColor;
-(void)setSliceBackgroundColor:(NSColor*)color;
-(float)cursorSize;
-(void)setCursorSize:(float)size;
-(NSColor*)cursorColor;
-(void)setCursorColor:(NSColor*)color;
-(BOOL)cursorIsVisible;
-(void)setCursorIsVisible:(BOOL)flag;
-(BOOL)showCursorHighlight;
-(void)setShowCursorHighlight:(BOOL)value;
-(NSColor*)cursorHighlightColor;
-(void)setCursorHighlightColor:(NSColor*)color;
-(enum colorSpaceType)colorSpace;
-(void)setColorSpace:(enum colorSpaceType)value;
-(int)traOversampling;
-(void)setTraOversampling:(int)value;
-(int)sagOversampling;
-(void)setSagOversampling:(int)value;
-(int)corOversampling;
-(void)setCorOversampling:(int)value;
-(MyVolumeController*)overlayController;
-(void)setOverlayController:(MyVolumeController*)controller;
-(IBAction)clearOverlayController:(id)sender;
-(float)overlayOpacity;
-(void)setOverlayOpacity:(float)value;
-(BOOL)validateOverlayOpacity:(id*)ioValue error:(NSError **)outError;
-(float)overlayThreshold;
-(void)setOverlayThreshold:(float)value;
-(BOOL)validateOverlayThreshold:(id*)ioValue error:(NSError **)outError;
-(NSString*)coordsString;
-(enum directionType)plotDimension;
-(NSString*)plotTitle;
-(void)setPlotTitle:(NSString*)string;
-(NSString*)plotXlabel;
-(void)setPlotXlabel:(NSString*)string;
-(NSString*)plotYlabel;
-(void)setPlotYlabel:(NSString*)string;
-(void)setPlotDimension:(enum directionType)value;
-(BOOL)validatePlotDimension:(id*)ioValue error:(NSError**)outError;
-(BOOL)triplanarViewsAreVisible;
-(void)setTriplanarViewsAreVisible:(BOOL)value;
-(BOOL)includeTimeWhenSyncingCoords;
-(void)setIncludeTimeWhenSyncingCoords:(BOOL)value;
-(id)plotDecorator;
-(void)setPlotDecorator:(id)value;
-(NSView*)plotView;
-(NSTabView*)tabView;

// ROI Support
-(IBAction)newDocument:(id)sender;
-(id)newVolume;
-(IBAction)newOverlay:(id)sender; // Create new doc and set as overlay for ROI painting
-(NSUndoManager*)windowWillReturnUndoManager:(NSWindow*)sender;
-(void)didPerformUndo:(NSNotification *)aNotification;
-(BOOL)computeRegionStats;
-(void)setComputeRegionStats:(BOOL)value;
-(float)lowerRegionThreshold;
-(void)setLowerRegionThreshold:(float)value;
-(float)upperRegionThreshold;
-(void)setUpperRegionThreshold:(float)value;
-(NSArray*)regionSignals;
-(void)setRegionSignals:(NSArray*)value;
-(NSDictionary*)regionStatistics;
-(void)setRegionStatistics:(NSDictionary*)value;
-(void)updateSettingsForNewValue:(float)value inVolume:(id)theVolume;
-(NSNumber*)regionMean;
-(NSNumber*)regionStandardDeviation;
-(NSNumber*)regionMedian;
-(NSNumber*)numberOfVoxelsInRegion;
-(NSNumber*)regionVolume;
-(NSNumber*)regionMin;
-(NSNumber*)regionMax;

// View Coordinates
-(int)row;
-(void)setRow:(int)value;
-(BOOL)validateRow:(id*)ioValue error:(NSError**)outError;
-(int)column;
-(void)setColumn:(int)value;
-(BOOL)validateColumn:(id*)ioValue error:(NSError**)outError;
-(int)slice;
-(void)setSlice:(int)value;
-(BOOL)validateSlice:(id*)ioValue error:(NSError**)outError;
-(int)frame;
-(void)setFrame:(int)value;
-(BOOL)validateFrame:(id*)ioValue error:(NSError**)outError;

-(float)xspace;
-(void)setXspace:(float)value;
-(float)maxXspace;
-(BOOL)validateXspace:(id*)ioValue error:(NSError**)outError;
-(float)yspace;
-(void)setYspace:(float)value;
-(float)maxYspace;
-(BOOL)validateYspace:(id*)ioValue error:(NSError**)outError;
-(float)zspace;
-(void)setZspace:(float)value;
-(float)maxZspace;
-(BOOL)validateZspace:(id*)ioValue error:(NSError**)outError;
-(float)time;
-(void)setTime:(float)value;
-(float)maxTime;
-(BOOL)validateTime:(id*)ioValue error:(NSError**)outError;

-(float)worldx;
-(void)setWorldx:(float)value;
-(float)worldy;
-(void)setWorldy:(float)value;
-(float)worldz;
-(void)setWorldz:(float)value;

  // Volume size
-(int)numRows;
-(void)setNumRows:(int)value;
-(int)numColumns;
-(void)setNumColumns:(int)value;
-(int)numSlices;
-(void)setNumSlices:(int)value;
-(int)numFrames;
-(void)setNumFrames:(int)value;
-(NSMutableDictionary*)currentCoords;
-(void)setCurrentCoords:(NSMutableDictionary*)coords;

// View Actions
-(IBAction)syncCoords:(id)sender;
-(IBAction)setMiscDefaults:(id)sender;
-(IBAction)setDefaultCoordinates:(id)sender;
-(IBAction)setDefaultWindowLevels:(id)sender;
-(IBAction)setDefaultCursorSettings:(id)sender;
-(void)setCoordsToX:(float)x y:(float)y inSlicePlane:(enum orientationType)orientation;
-(void)setDataValue:(float)val atX:(float)x y:(float)y inSlicePlane:(enum orientationType)orientation
             coords:(NSDictionary*)theCoords;
-(void)setDataValue:(float)val forMosaicImage:(MyMosaicImage*)mosaic x:(float)x y:(float)y inSlicePlane:(enum orientationType)orientation;
-(void)paintValue:(float)val inRegion:(NSBezierPath *)path ofImage:(id)image inSlicePlane:(enum orientationType)orientation coords:(NSDictionary*)theCoords;
-(IBAction)incrementIndex:(id)sender;
-(void)incrementIndexBy:(int)delta inDirection:(int)direction;
-(void)coordinatesDidChange:(NSNotification *)aNotification;
-(IBAction)gotoWorldOrigin:(id)sender;
-(IBAction)syncWindowSettings:(id)sender;
-(IBAction)syncPlotSettings:(id)sender;
-(IBAction)resetPlotSettingsAll:(id)sender;
-(void)resetPlotSettings:(NSNotification *)aNotification;
-(void)changeWindowSettings:(NSNotification *)aNotification;
-(void)changePlotSettings:(NSNotification *)aNotification;
-(IBAction)resetWindowSettingsAll:(id)sender;
-(void)resetWindowSettings:(NSNotification *)aNotification;

-(IBAction)syncCursorSettings:(id)sender;
-(void)changeCursorSettings:(NSNotification *)aNotification;
-(IBAction)resetCursorSettingsAll:(id)sender;
-(void)resetCursorSettings:(NSNotification *)aNotification;

-(IBAction)setColorSpaceForMenuItem:(id)sender;
-(void)syncColorSpaceMenuItemsToValue:(enum colorSpaceType)value;
-(NSArray*)colorSpaceNameArray;
-(IBAction)setViewTabForMenuItem:(id)sender;
-(IBAction)setViewTabForAll:(id)sender;
-(void)changeViewTab:(NSNotification *)aNotification;

// Window management
-(void)setupToolbar;
-(void)setDefaultNotifications;
-(void)windowDidBecomeMain:(NSNotification *)aNotification;
-(BOOL)windowShouldClose:(id)sender;
-(void)windowWillClose:(NSNotification *)aNotification;
-(void)aWindowWillClose:(NSNotification *)aNotification;
-(IBAction)toggleInspectorDrawer:(id)sender;

// Internal methods
-(void)syncToIndexCoords;
-(void)syncToVolumeCoords;
-(void)syncToWorldCoords;
-(NSMutableDictionary*)coordsForIndexCoords:(NSDictionary*)coords;
-(NSMutableDictionary*)coordsFromVolumeCoords:(NSDictionary*)inCoords;
-(BOOL)worldCoordsAreInVolume:(NSDictionary*)coords;
-(IBAction)removeOverlay:(id)sender;
-(IBAction)showOverlay:(id)sender;
-(void)addObserversForAllKeysInDictNamed:(NSString*)dictName;
-(void)removeObserversForAllKeysInDictNamed:(NSString*)dictName;

// NSSplitView delegate methods
-(void)splitViewDidResizeSubviews:(NSNotification *)aNotification;
-(BOOL)splitView:(NSSplitView *)sender canCollapseSubview:(NSView *)subview;
-(void)fixTabViewItemSizes:(NSTabView*)theTabView; // Internal workaround
  
// Images
-(NSImage*)sliceImageForView:(enum orientationType)orientation;
-(NSImage*)traSliceImage;
-(void)setTraSliceImage:(NSImage*)image;
-(NSImage*)sagSliceImage;
-(void)setSagSliceImage:(NSImage*)image;
-(NSImage*)corSliceImage;
-(void)setCorSliceImage:(NSImage*)image;

-(MyMosaicImage*)mosaicImageForView:(enum orientationType)orientation;
-(MyMosaicImage*)traMosaicImage;
-(void)setTraMosaicImage:(MyMosaicImage*)image;
-(MyMosaicImage*)sagMosaicImage;
-(void)setSagMosaicImage:(MyMosaicImage*)image;
-(MyMosaicImage*)corMosaicImage;
-(void)setCorMosaicImage:(MyMosaicImage*)image;

-(NSImage*)oversampleImage:(NSImage*)image byFactorOf:(int)factor;
-(NSImage*)combineImage:(NSImage*)image1 withImage:(NSImage*)image2 opacity:(float)opacity;
-(MyMosaicImage*)combineMosaicImage:(MyMosaicImage*)image1 withImage:(MyMosaicImage*)image2;

// Signals
-(NSArray*)signals;

@end

@interface MyVolumeController (MyVolumeInfoCategory)

-(IBAction)showDocumentInfo:(id)sender;
-(IBAction)stopDocumentInfo:(id)sender;

-(int)numberOfRowsInTableView:(NSTableView *)tableView;
-(id)tableView:(NSTableView *)tableView objectValueForTableColumn:(NSTableColumn *)tableColumn row:(int)row;
-(void)tableView:(NSTableView *)aTableView
  setObjectValue:(id)anObject
  forTableColumn:(NSTableColumn *)aTableColumn
             row:(int)rowIndex;
-(IBAction)addDemographicInfoKey:(id)sender;
-(IBAction)removeDemographicInfoKey:(id)sender;

@end


