//
//  MyVolume.h
//  NeuroLens
//
//  Created by Rick Hoge on Tue Mar 16 2004.
//  Copyright (c) 2004 Martinos Center for Biomedical Imaging. All rights reserved.
//

//  This document subclass is used for volumes or series of volumes (3D or 4D datasets).
//  It uses its own nib file and sets up controller objects appropriate for this purpose.
//
//  This subclass is associated with certain file types via entries in the application bundles's Info.plist file

#import "MyDocument.h"
#import "MyVolumeController.h"
#import "MyMosaicImage.h"
#import "NLTransform.h"

@interface MyVolume : MyDocument <NSCoding, NSMutableCopying> {

  // These are volume-specific attributes
  
  NSMutableArray      *dimNames;    // list of dim names
  NSMutableDictionary *dimLengths;  // lengths of all dims, retrievable by name
  NSMutableDictionary *dimSteps;    // steps of all dims, retrievable by name
  NSMutableDictionary *dimStarts;   // starts of all dims, retrievable by name
  NSMutableDictionary *dimDirCosines; // dir cosines of all dims, retrievable by name

  NLTransform *transform; // Spatial Transform used to convert to world coords
  
  ////////// Convenience attributes that simplify description of dataset /////////////////
  
  int numDims; // number of dimensions (redundant with length of dimNames)
  enum orientationType fileOrientation; // native slice orientation (redundant with order of dimNames)
  
  // Lookup tables for mapping physical dims to and from index dims
  NSDictionary *physicalDimLookup;
  NSDictionary *indexDimLookup;
  
  
}

// Initialization
-(void)configWithData:(NSMutableData *)data
             dimNames:(NSMutableArray *)_dimNames
           dimLengths:(NSMutableDictionary *)_dimLengths
             dimSteps:(NSMutableDictionary *)_dimSteps
            dimStarts:(NSMutableDictionary *)_dimStarts
        dimDirCosines:(NSMutableDictionary *)_dimDirCosines
      fileOrientation:(enum orientationType)_fileOrientation
    minIntensityValue:(double)_minIntensityValue
    maxIntensityValue:(double)_maxIntensityValue
             dataType:(enum DATA_TYPE)_dataType
          numDataDims:(int)_numDataDims;

  // Accessors
-(NSMutableDictionary*)dimLengths;
-(void)setDimLengths:(NSMutableDictionary*)value;
-(NSMutableDictionary*)dimSteps;
-(void)setDimSteps:(NSMutableDictionary*)value;
-(enum orientationType)fileOrientation;
-(void)setFileOrientation:(enum orientationType)value;
-(NSMutableDictionary*)dimDirCosines;
-(void)setDimDirCosines:(NSMutableDictionary*)value;
-(NSMutableDictionary*)dimStarts;
-(void)setDimStarts:(NSMutableDictionary*)value;
-(NSMutableArray*)dimNames;
-(void)setDimNames:(NSMutableArray*)value;
-(NSDictionary*)indexDimLookup;
-(void)setIndexDimLookup:(NSDictionary*)value;
-(NSDictionary*)physicalDimLookup;
-(void)setPhysicalDimLookup:(NSDictionary*)value;
-(float)dataSize;
-(int)numVoxelsVolume;
-(int)numVoxelsSeries;
-(int)numDims;
-(void)setNumDims:(int)value;
-(NLTransform*)transform;
-(void)setTransform:(NLTransform*)value;

// File format support
-(BOOL)readMINCFile:(NSString*)fileName;
-(BOOL)readMGHFile:(NSString*)fileName;
-(BOOL)readAFNIFile:(NSString*)fileName;
-(NSMutableArray*)parseNumericField:(NSString*)tag fromAfniHeader:(NSString*)header; // AFNI Support
-(NSString*)parseStringField:(NSString*)tag fromAfniHeader:(NSString*)header; // AFNI Support
-(BOOL)readCORFile:(NSString*)fileName;
-(NSArray*)scanThreeFloatsFrom:(NSString*)info forTag:(NSString*)tag; // COR Support
-(BOOL)readAnalyzeFile:(NSString*)fileName;
-(void)setIconForFile:(NSString*)fullDocumentPath;
-(BOOL)readDicomFile:(NSString*)fileName;
-(BOOL)readTIFFFile:(NSString*)fileName;
-(BOOL)readNIfTIFile:(NSString*)fileName;

// Output
-(BOOL)writeToMINCFile:(NSString*)fullDocumentPath;
-(BOOL)writeToNIFTIFile:(NSString*)fullDocumentPath;

// Coordinate system support
-(void)initDimensionLookupsForOrient:(enum orientationType)orientation; // Initialize dimension dictionaries for file orientation (tra,sag,cor)
-(BOOL)isSampledLike:(MyVolume*)volume;
//-(NSData*)worldCoordsForSlice:(enum orientationType)viewOrientation inVolume:(MyVolume*)target atCoords:(NSDictionary *)coords;
-(void)copyCoordinatesFrom:(MyVolume*)volume;
-(NSData*)worldCoordinateGrid; // list of voxel world coordinates for this volume

// Image operations
-(NSArray*)alignedRowSizesSamplesPerPixel:(int)spp imageWidth:(int)imageWidth;
-(NSImage*)horizontalReflectImage:(NSImage*)image;
-(NSImage*)verticalReflectImage:(NSImage*)image;
-(MyMosaicImage*)horizontalReflectMosaicImage:(MyMosaicImage*)image;

// Data access
-(NSArray*)getValueAtLocation:(NSDictionary*)coords; // Get image value at specified location
-(void)setValue:(float)value atLocation:(NSDictionary*)coords; // Set image value at specified location
-(NSArray*)getProfile:(enum directionType)direction atLocation:(NSDictionary*)coords; // Get spatial or temporal profile
-(NSDictionary*)statisticsForOverlay:(MyVolume*)overlay lowerThreshold:(float)lowerThreshold upperThreshold:(float)upperThreshold;

-(NSMutableData*)getSliceDataWithOrientation:(enum orientationType)viewOrientation 
                                   forCoords:(NSDictionary *)theCoords;


-(NSImage*)getSliceBitmapWithOrientation:(enum orientationType)viewOrientation  // Return cross-sectional image
                                forCoords:(NSDictionary *)theCoords
                           withColorSpace:(enum colorSpaceType)colorSpace
                     withLowerWindowLevel:(float)lowerWindowLevel
                     withUpperWindowLevel:(float)upperWindowLevel
                           withThreshold:(float)threshold;

-(NSImage*)getSliceBitmapWithOrientation:(enum orientationType)viewOrientation 
                                fromData:(NSData*)imageData
                          withColorSpace:(enum colorSpaceType)colorSpace
                    withLowerWindowLevel:(float)lowerWindowLevel
                    withUpperWindowLevel:(float)upperWindowLevel
                           withThreshold:(float)threshold 
                             withOpacity:(float)opacity;

-(NSImage*)getSliceBitmapWithOrientation:(enum orientationType)viewOrientation  // Return cross-sectional image
                               forCoords:(NSDictionary *)theCoords
                          withColorSpace:(enum colorSpaceType)colorSpace
                    withLowerWindowLevel:(float)lowerWindowLevel
                    withUpperWindowLevel:(float)upperWindowLevel
                           withThreshold:(float)threshold
                             sampledLike:(MyVolume*)volume;

-(MyMosaicImage*)getMosaicBitmapWithOrientation:(enum orientationType)viewOrientation  // Return mosaic of slices
                                      forCoords:(NSDictionary *)theCoords
                                 withColorSpace:(enum colorSpaceType)colorSpace
                           withLowerWindowLevel:(float)lowerWindowLevel
                           withUpperWindowLevel:(float)upperWindowLevel
                                  withThreshold:(float)threshold;

-(NSMutableData*)colorsAtWorldX:(NSData*)xvals 
                              y:(NSData*)yvals 
                              z:(NSData*)zvals 
                              t:(NSData*)tvals 
                 withColorSpace:(enum colorSpaceType)colorSpace
           withLowerWindowLevel:(float)lowerWindowLevel
           withUpperWindowLevel:(float)upperWindowLevel;

-(NSMutableData*)valuesAtWorldX:(NSData*)xvals 
                              y:(NSData*)yvals 
                              z:(NSData*)zvals 
                              t:(NSData*)tvals;

-(NSMutableData*)valuesAtVolumeX:(NSData*)xvals 
                               y:(NSData*)yvals 
                               z:(NSData*)zvals 
                               t:(NSData*)tvals;

@end
