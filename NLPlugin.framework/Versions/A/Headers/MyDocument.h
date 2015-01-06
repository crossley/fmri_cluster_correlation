//
//  MyDocument.h
//  NeuroLens
//
//  Created by Rick Hoge on Tue Mar 16 2004.
//  Copyright (c) 2004 Martinos Center for Biomedical Imaging. All rights reserved.
//

// This is a general purpose document class that can be subclassed for specific types
// such as volume series and surfaces.  This class contains the basic elements expected
// to be common to all subclasses - basically a block of binary data representing the measured
// values (could be scalar or vector values at voxels or on a surface).

#import <Cocoa/Cocoa.h>

// General includes such as enumerated types
#import "includes.h"

@interface MyDocument : NSDocument <NSCoding, NSMutableCopying> {
  
  NSMutableData *theData; // The voxel data matrix, which may have any number of dimensions
    
  // Info about intensity range
  float minIntensityValue;
  float maxIntensityValue;

  // Info about the type of quantitative data
  enum DATA_TYPE dataType;  // e.g. float vs short vs byte vs vector
  int numDataDims; // Dimensionality of data values (scalar:  1  vector:  >1)
  
  ////////////////////// Descriptive Information //////////////////////////////////////////
  
  NSMutableDictionary *acquisitionInfo; // Information about data acquisition settings
  NSMutableArray *processingInfo; // Sequence of operations used to generate this dataset
  NSMutableDictionary *displayInfo; // Display information
  NSMutableDictionary *demographicInfo; // Information about subject demographics
  NSMutableDictionary *annotationInfo; // Information about file annotations
  NSMutableDictionary *experimentInfo; // Information about file annotations
  
  // Progress indicator support
  IBOutlet NSButton *cancelButton;
  IBOutlet NSProgressIndicator *progressIndicator;
  IBOutlet NSWindow *progressWindow;
  IBOutlet NSTextField *progressMessage;
  BOOL hideCancelButton;
  NSString *processingStatus;
  
  // Window management
  NSWindowController *windowController;
  
}

-(NSString*)processingStatus;
-(void)setProcessingStatus:(NSString*)value;

-(float)minIntensityValue;
-(void)setMinIntensityValue:(float)value;
-(float)maxIntensityValue;
-(void)setMaxIntensityValue:(float)value;
-(float)maxAbsoluteValue;

-(enum DATA_TYPE)dataType;
-(void)setDataType:(enum DATA_TYPE)type;

-(NSMutableData*)theData;
-(void)setTheData:(NSMutableData*)data;

-(NSMutableData*)theDataAsFloat;

-(int)numDataDims;
-(void)setNumDataDims:(int)value;

-(NSMutableDictionary*)acquisitionInfo;
-(void)setAcquisitionInfo:(NSMutableDictionary*)value;

-(NSMutableDictionary*)demographicInfo;
-(void)setDemographicInfo:(NSMutableDictionary*)value;

-(NSMutableDictionary*)experimentInfo;
-(void)setExperimentInfo:(NSMutableDictionary*)dictionary;

-(NSMutableArray*)processingInfo;
-(void)setProcessingInfo:(NSMutableArray*)dictionary;

-(NSArray*)processingInfoForOutline; // Formatted to work with outline view
-(NSArray*)processingResultsForOutline; // Formatted to work with outline view

-(NSArray*)sortDescriptorForProcInfo;

-(NSMutableDictionary*)annotationInfo;
-(void)setAnnotationInfo:(NSMutableDictionary*)value;

-(NSMutableDictionary*)displayInfo;
-(void)setDisplayInfo:(NSMutableDictionary*)dictionary;

-(BOOL)hideCancelButton;
-(void)setHideCancelButton:(BOOL)value;

-(NSWindowController*)windowController;
-(void)setWindowController:(NSWindowController*)value;

-(BOOL)writeWithBackupToFile:(NSString*)fullDocumentPath ofType:(NSString*)docType saveOperation:(NSSaveOperationType)saveOperationType;

-(void)setFinderComment:(NSString*)comment atPath:(NSString*)fullPath;

-(void)setDisplayName:(NSString*)value; // Dummy method to get rid of runtime warning with KVO

-(void)dump; // Dump out info about the dataset

// Progress support
-(IBAction)cancelOperation:(id)sender;

@end
