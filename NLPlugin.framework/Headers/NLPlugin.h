//
//  NLPlugin.h
//  NeuroLens
//
//  Created by Rick Hoge on Sun Apr 18 2004.
//  Copyright (c) 2004 __MyCompanyName__. All rights reserved.
//
//  This file defines the base class for NeuroPlugins, which is provided to the 
//  developer as a framework.  Note that the main target should contain a dependency on
//  the framework, but should *not* include the implementation (.m file) for this class.
//  Both the main app and plugin targets should link against the framework.

#import <Cocoa/Cocoa.h>
#import "MyVolume.h"
#import "NLTransform.h"

/*! 
@class NLPlugin
Base class for NeuroLens plugin.
*/
@interface NLPlugin : NSObject <NSCoding, NSCopying> {

  // Info about how plugin is being run
  BOOL isInteractive;
  BOOL isThreaded;
  NSString *jobDir; // Working directory if invoked through nldo

  // Processing parameters
  MyDocument *srcDocument;
  
  // Interactive stuff
  IBOutlet NSPanel *pluginSheet; // Sheet used to configure plugin interactively
  NSModalSession pluginSession; // Modal session used during configuration
  IBOutlet NSPanel *progressWindow;
  IBOutlet NSProgressIndicator *progressIndicator;
  IBOutlet NSTextField *progressMessage;
  BOOL hideCancelButton;
  BOOL guiIsEnabled; // Flag used to enable/disable GUI 
  
}

// Init methods
/*! 
@method plugin
@discussion Returns an autoreleased plugin instance, newly initialized.
*/
+(id)plugin;

// Accessors

/*! 
@method isInteractive
@discussion Return value indicates whether plugin is being run in an interactive session or from a script.
*/
-(BOOL)isInteractive;
/*! 
@method setIsInteractive
@discussion Sets flag determining whether plugin will perform operations needed for interactive mode.
*/
-(void)setIsInteractive:(BOOL)value;

/*! 
@method isThreaded
@discussion Return value indicates whether plugin is being run in a background thread.
*/
-(BOOL)isThreaded;
/*! 
@method setIsThreaded
@discussion Sets flag determining whether plugin will perform operations needed if run as background thread.
*/
-(void)setIsThreaded:(BOOL)value;

/*!
@method hideCancelButton
@discussion Returns YES if cancel button in progress window is not shown for this plugin.
*/
-(BOOL)hideCancelButton;
/*!
@method setHideCancelButton:
@discussion Set to YES if you do not want a cancel button to be shown on the progress window for this plugin.
*/
-(void)setHideCancelButton:(BOOL)value;

/*!
  @method guiIsEnabled
  @discussion Returns YES if controls on plugin configuration sheet should be enabled.
*/
-(BOOL)guiIsEnabled;
/*!
  @method setGuiIsEnabled Set to NO if you want controls on plugin configuration sheet to be disabled.  This can be used to display the sheet on an output dataset without permitting changes to parameters.
*/
-(void)setGuiIsEnabled:(BOOL)value;

/*!
  @method srcDocument
  @discussion Returns the input document for the plugin.
*/
-(MyDocument*)srcDocument;
/*!
  @method setSrcDocument:
  @discussion Set the input document for the plugin.
*/
-(void)setSrcDocument:(MyDocument*)value;

-(NSString*)jobDir;
-(void)setJobDir:(NSString*)value;

// Validation
-(BOOL)canProcessDocument:(id)document; // For menu validation
-(NSMutableArray*)compatibleVolumes; // Returns other open volumes with same grid size

// Execution
-(void)launchInteractivelyForDocument:(MyDocument*)doc;
-(void)configureInteractivelyForSequence;
-(void)setDefaultsForDocument:(MyDocument*)doc;
-(IBAction)doInteractiveProcessing:(id)sender;
-(NSArray*)run; // Run and return output documents
-(void)pluginSheetDidEnd:(NSWindow *)sheet returnCode:(int)returnCode contextInfo:(void*)contextInfo;
-(IBAction)abortInteractiveSetup:(id)sender;
-(IBAction)cancelOperation:(id)sender; // Cancel a processing operation

// Help
-(IBAction)showPluginHelp:(id)sender;
-(NSString*)help;

// File name processing
-(NSString *)makeNewNameFrom:(NSString *)oldName withTag:(NSString *)tag;
-(NSString*)makeNameFromString:(NSString*)string bySubstitutingEnding:(NSString*)tag1 withEnding:(NSString*)tag2;

// Decoration Support
-(NSArray*)decorationSignalsAtCoords:(NSDictionary*)coords;
//-(NSString*)plotDecorationTitle;

// Job sharing support
-(NSString*)info; // Name with settings
-(IBOutlet NSPanel*)pluginSheet;

// AppleScript support
-(NSString*)description;
-(void*)runFromAppleScript:(NSScriptCommand*)command;

// DO Scripting support
-(Class)classForKey:(NSString*)key;
-(id)objectForKey:(NSString*)key fromArgList:(NSEnumerator*)args;

@end
