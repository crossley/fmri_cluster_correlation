//
//  fmri_cluster_correlation.m
//  fmri_cluster_correlation
//
//  Created by crossley on 11/30/10.
//  Copyright __MyCompanyName__ 2010 . All rights reserved.
//

#import "fmri_cluster_correlation.h"

@implementation fmri_cluster_correlation

#pragma mark
#pragma mark ---- Initialization ----
#pragma mark

-(id)init {
  
  // This method is invoked whenever a new plugin is created (this is done automatically 
  // by the main app when the plugin is selected).
  // It should be used to set default values of processing parameters
  
  self = [super init];
  
  if(self) {

    // Set default values of processing parameters here
    // (these instance variables are defined in fmri_cluster_correlation.h)
    
  }
  
  return self;
}

-(void)dealloc {
 
  // This method is invoked when the plugin object is deallocated.
  
  // You should release any instance variables that are objects here 
  // (e.g NSString, NSArray, NSNumber etc.).  If you don't do this
  // you will be leaking memory.

  [super dealloc]; // Call this last to deallocate instance variables in parent class
  
}

#pragma mark
#pragma mark ---- DO Scripting Support ----
#pragma mark

// The following two methods are only needed if you want to support scripted invocation of
// your plugin using NeuroLens Distributed Objects support via the nldo command. 
// They are not required for interactive sessions and so are commented
// out in the plugin.  Typically you will first get the plugin working interactively, then
// add the small amount of code needed to support command-line processing.

/*
-(Class)classForKey:(NSString*)key {

  // This method returns the class of the instance variable whose name is 'key'.
  // The commented-out code shows how this would be done for an NSString variable called myString
  // and an numeric variable called myNumber, allowing the following (hypothetical) command-line invocation:
  //
  // nldo run 'fmri_cluster_correlation' -srcDocument file.mnc -myString Gaussian -myNumber 6.0
  //
  // Note that srcDocument is an instance variable of the parent plugin class and 
  // so is handled in the 'else' block below.
  
  // This method is required if you want to be able to run your plugin from a script.
  
  if ([key isEqualToString:@"myString"]) {
    return [NSString class]; 
  } else if ([key isEqualToString:@"myNumber"]) {
    return [NSNumber class]; 
  } else {
    return [super classForKey:key]; // Let the parent class handle its own instance variables
  }
  
}
*/

/*
-(id)objectForKey:(NSString*)key fromArgList:(NSEnumerator*)args {

  // This method provides custom argument parsing required when there are multiple values for
  // a key and the corresponding instance variable is a compound object like an 
  // NSArray or NSDictionary
  //
  // Simple value types like numbers and strings can be handled by the parent plugin class.
  //
  // The following shows an example of a command-line invocation that would require this support
  //
  // nldo run 'fmri_cluster_correlation' -srcDocument file.mnc -myString Gaussian -myNumber 6.0 -myCustomArgs 'Contrast Name' '1 0 -1'
  //
  // The values 'Contrast Name' and '1 0 -1' for the parameter key 'myCustomArgs' would be handled in the first block of the 'if' statement below
  
  // This method is optional - it is only required if any of your scriptable parameters are more complex 
  // than numbers or strings.
  
  if ([key isEqualToString:@"myCustomArgs"]) {
    // Do custom extraction here
  } else {
    return [super objectForKey:key fromArgList:args]; // Let the parent class handle all the standard types
  }
  
}
*/

#pragma mark
#pragma mark ---- Accessor Methods ----
#pragma mark

// Define accessor methods for any instance variables that will require set and get methods here.
// Note that accessor methods are not needed to control instance variables by binding to UI elements.
// You might not need to write any accessors!
// Accessors _are_ required if you want to support the NSCopying protocol, however (see below).

// e.g. for basic C type:
// -(float)myFloat { return myFloat; }
// -(void)setMyFloat:(float)value { myFloat = value; }

// e.g. for object:
// -(NSObject*)myObject { return myObject; }
// -(void)setMyObject:(NSObject*)object {
//  [object retain];
//  [myObject release];
//  myObject = object;
// }

#pragma mark
#pragma mark ---- Description and Validation ----
#pragma mark

-(NSString*)description{ return @"fmri_cluster_correlation"; }

-(NSString*)info { return @"fmri_cluster_correlation"; }

-(BOOL)canProcessDocument:(id)doc {

  // This method is called whenever the contents of the Plugins menu are exposed.
  //
  // It should indicate whether the plugin can operate on the input document (doc).
  // This is how plugin menu items are enabled or greyed out for the active document in an interactive session.

  // Criteria that could be tested include:
  //   - does document have multiple time points?
  //   - is the data type (short, float, vector) supported?
  //   - is doc a volume or a surface?
  // What you exclude will depend on the processing operation and what situations you
  // decide to support in your code.
  
  // Put most likely problems first, and avoid NSLog's (will degrade performance)
  
  if (!doc) return NO; // Can't process if there's no document
  
  // Must be a volume (or respond to selector dimLengths - selector is another name for Objective-C message)
  if (![doc respondsToSelector:@selector(dimLengths)]) return NO;

  // Check to see if document contains short integer data (SHORTDATA | FLOATDATA | VECTORDATA)
  // Our template plugin just supports short ints, but you can support any of the above types.
  if ([doc dataType]!=SHORTDATA) return NO;
  
  // Could test to see if document is a time-series
  // if ([[[doc dimLengths] objectForKey:@"frame"] intValue] <= 1) return NO;

  // If no problems, we can process the document
  return YES;
}

#pragma mark
#pragma mark ---- Execution ----
#pragma mark

-(void)setDefaultsForDocument:(MyDocument*)doc {

  // This method gets called after the plugin has been launched with a specific input
  // dataset but before the UI sheet is displayed.
  
  // In this method you should set any default values that depend on
  // the input dataset and which you want to be reflected in the UI sheet
  // for the plugin (this method is called right before the sheet is drawn).
  
  // The init method is called before an input document
  // is assigned, so those defaults can not depend on characteristics of the input.
  
  // For example in an fMRI analysis you might assign a default design that
  // depends on the number of time points in a dataset.  This could be done here, and
  // the resultant default could be displayed in the UI sheet.

  // If you don't need to do any document-specific initialization before the UI is shown, 
  // you can just leave this empty (you can also get document-specific info in the run method,
  // but this will happen after the sheet closes).
  
}

-(NSArray*)run {

  // This method is called right after the user clicks 'OK' on the plugin UI sheet.
  
  // This is where the actual processing takes place.
  // You should make sure that all plugin settings (instance variables) have
  // been fully configured before this method is called.
  
  // This method generally returns an array of fully configured documents, which
  // will be automatically displayed (and saved if that preference is set).

  // Note that is is not essential to return any datasets - you could just return a nil value.
  // This would be useful if you just wanted the plugin to load its own nib to display some 
  // result or representation of the input data, or perform your own 

  // A simple plugin requiring no UI configuration (or using hard-coded values) could be written
  // by only adding code to this method.

  // Pointer to input dataset, cast as volume type (as opposed to surface, etc.)
  MyVolume *srcSeries = (MyVolume*)srcDocument;
  
  // Get some info about the dataset (e.g. dimension lengths)
  int numRows = [[[srcSeries dimLengths] objectForKey:@"row"] intValue];
  int numColumns = [[[srcSeries dimLengths] objectForKey:@"column"] intValue];
  int numSlices = [[[srcSeries dimLengths] objectForKey:@"slice"] intValue];
  int numFrames = [[[srcSeries dimLengths] objectForKey:@"frame"] intValue];
	
  // Number of voxels in volume, series
  long numVoxelsVolume = numRows * numColumns * numSlices;
  long numVoxelsSeries = numVoxelsVolume * numFrames;
	
	NSLog(@"%i %i", numFrames, (int) numVoxelsSeries);
  
  // Get pointer to the data for this volume/series (use const because we won't change the input data)
  const short *dataPointer = [[srcSeries theData] bytes];
  // We know the data will be short int, because of checks in canProcessDocument

  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
  ////// Here we do a simple processing operation (copy the data bytes of input dataset) - replace this with your code! ///////////
  /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int i,j,k,ii,jj,kk,t;
	int ix,iy; 

	// Create data object for output dataset 
	NSMutableData* newData = [NSMutableData dataWithLength:numVoxelsSeries*sizeof(short)];
	short *newDataPointer = [newData mutableBytes]; // Pointer to new data object
	
	// Create data object for output dataset 
	NSMutableData* statData = [NSMutableData dataWithLength:numVoxelsVolume*sizeof(float)];
	float *statPointer = [statData mutableBytes]; // Pointer to new data object
	
	// load in TR vector
	int result;
	NSArray *fileTypes = [NSArray arrayWithObject:@"dat"];
	NSOpenPanel *oPanel = [NSOpenPanel openPanel];
	
	[oPanel setAllowsMultipleSelection:NO];
	result = [oPanel runModalForDirectory:NSHomeDirectory() file:nil types:fileTypes];
	if (result == NSOKButton) 
	{
		NSArray *filesToOpen = [oPanel filenames];
		filePath = [filesToOpen objectAtIndex:0];
	}
	
	FILE *ev_ind_File;
	ev_ind_File = fopen([filePath cStringUsingEncoding:1],"r");
	
	if(ev_ind_File != NULL)
	{			
		ev_ind  = (int*) calloc(480,sizeof(int*));
		
		for(i=0; i<480; i++)
		{
			fscanf(ev_ind_File, "%i\n", &ev_ind[i]);
		}
		
		fclose(ev_ind_File);
	}
	
	// Copy data from input to output
	NSLog(@"Doing processing..."); // Message to console
		
	currentVoxelTimeSeries = (float*) calloc(numFrames, sizeof(float));
	currentVoxelTimeSeries_zeroMean = (float*) calloc(numFrames, sizeof(float));
	currentVoxelTimeSeriesMean = 0.0;
		
	for (ix=0; ix<numVoxelsVolume; ix++) 
	{ 
		// For each voxel, extract it's time series
		// Contiguous entries in dataPointer are columns (adjacent voxels within a column). The next 'loop' is rows, then slices, then frames.
		for(iy=0; iy<numFrames; iy++)
		{
			*(currentVoxelTimeSeries+iy) = (float) *(dataPointer+(iy*numVoxelsVolume+ix));
		}
		
		// compute the mean of the time series we just constructed
		currentVoxelTimeSeriesMean = 0.0;
		vDSP_meanv(currentVoxelTimeSeries, 1, &currentVoxelTimeSeriesMean, numFrames);
//		NSLog(@"%f", currentVoxelTimeSeriesMean);
		
		// zero mean the data
		currentVoxelTimeSeriesMean = -currentVoxelTimeSeriesMean;
		vDSP_vsadd (currentVoxelTimeSeries, 1, &(currentVoxelTimeSeriesMean), currentVoxelTimeSeries_zeroMean, 1, numFrames);
		
		// Now put the zero meaned data back into the dataPointer format
		for(iy=0; iy<numFrames; iy++)
		{
			*(newDataPointer+(iy*numVoxelsVolume+ix)) = (short) *(currentVoxelTimeSeries_zeroMean+iy);
		}
	}
		
	// Contiguous entries in dataPointer are columns (adjacent voxels within a column). The next 'loop' is rows, then slices, then frames.
	// So I think the following is true:
	// newDataPointer[i][j][k][t] = newDataPointer[i+j*numRows+k*numRows*numColumns+t*numRows*numColumns*numSlices]
	num_evs = 80;
	ev_length = 5;
	
	stat3 = (float*) calloc(numVoxelsVolume, sizeof(float));
	ERB_ave = (float*) calloc(ev_length, sizeof(float));
	HRF = (float*) calloc(ev_length, sizeof(float));
		
	HRF[0] = 1.0;
	HRF[1] = 2.0;
	HRF[2] = 3.0;
	HRF[3] = 2.0;
	HRF[4] = 1.0;
	
	int voxel = 0;
	int ev_onset = 0;
	ERB_rms = 0.0;
	HRF_ERB = 0.0;
	
	for(i=1; i<numColumns-1; i++)
	{
		NSLog(@"%i", i);
		for(j=1; j<numRows-1; j++)
		{
			for(k=1; k<numSlices-1; k++)
			{
				for(ii=i-1; ii<i+1; ii++)
				{
					for(jj=j-1; jj<j+1; jj++)
					{
						for(kk=k-1; kk<k+1; kk++)
						{
							// Define the index of the voxel that we are in
							voxel = ii+jj*numRows+kk*numRows*numColumns;
							
							// Get the time series for the voxel that we are in
							for(iy=0; iy<numFrames; iy++)
							{
								*(currentVoxelTimeSeries+iy) = (float) *(newDataPointer+(iy*numVoxelsVolume+voxel));
							}
							
							for(t=0; t<num_evs; t++)
							{
								// Use vector linear average to keep a running average of the ERBs in ERB_ave 
								// Recall that the values in ev_ind use the matlab indexing system. That's why we subtract 1.
								ev_onset = ev_ind[t]-1;
								vDSP_vavlin((float*) currentVoxelTimeSeries+ev_onset, 1, (float*) &t, ERB_ave, 1, ev_length);
							}
						}
					}
				}
				// First, compute <HRF,ERB_ave>
				vDSP_dotpr(HRF, 1, ERB_ave, 1, &HRF_ERB, ev_length);
								
				// Compute rms of ERB_ave
				vDSP_rmsqv(ERB_ave, 1, &ERB_rms, ev_length);
								
				// Calculate stat = HRF_ERB / ERB_rms
				*(stat3+i+j*numRows+k*numRows*numColumns) = HRF_ERB /  ERB_rms;
				*(statPointer+i+j*numRows+k*numRows*numColumns) = *(stat3+i+j*numRows+k*numRows*numColumns);
			}
		}
	}
	
  NSLog(@"Done.");
	  
  //////////////////////////////////////////////////////////////////////////////////////////
  // Now configure the output dataset - generally you will need to do something similar...
  //////////////////////////////////////////////////////////////////////////////////////////
  
  // Get pointer to document controller and tell it to create a new document
  NSDocumentController *dc = [NSDocumentController sharedDocumentController];
  id doc = [dc makeUntitledDocumentOfType:@"ca.mcgill.mni.bic.mnc"];

  // In general we might change the number of time points.
  // This would require new dictionary of dimension lengths...
  // Note that here we just use numFrames, the original length:
	
  // Modified this shit
  NSMutableDictionary *newDimLengths = [[srcSeries dimLengths] mutableCopy];
  [newDimLengths setObject:[NSNumber numberWithInt:1] forKey:@"frame"];
  [newDimLengths setObject:[NSNumber numberWithInt:1] forKey:@"time"];
  
  // Initialize the new document using info from old document and the new data and dimension length dictionary
  [doc configWithData:statData
             dimNames:[[srcSeries dimNames] copy]
           dimLengths:newDimLengths
             dimSteps:[[srcSeries dimSteps] copy]
            dimStarts:[[srcSeries dimStarts] copy]
        dimDirCosines:[[srcSeries dimDirCosines] copy]
      fileOrientation:[srcSeries fileOrientation]
    minIntensityValue:[srcSeries minIntensityValue] // Minimum data value (may change!)
    maxIntensityValue:[srcSeries maxIntensityValue] // Maximum data value (may change!)
             dataType:FLOATDATA // Type of data (SHORTDATA | FLOATDATA | VECTORDATA, may change!)
          numDataDims:[srcSeries numDataDims]]; // Number of dimensions in data (1 unless VECTORDATA; might change!)

  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  // Below are instructions that add descriptive metadata to the file.  Strictly speaking these are optional 
  // but you should try to be as complete as possible.
  ///////////////////////////////////////////////////////////////////////////////////////////////////////////
  
  // Generate new file name based on stem (change 'xxx' to your own string)
  [doc setFileName:[self makeNewNameFrom:[srcSeries fileName] withTag:@"xxx"]];

  // Set content description (optional but recommended - will be shown as Finder comment)
  [[doc annotationInfo] setObject:@"Output from fmri_cluster_correlation" forKey:@"contentDescription"];

  // Set display preferences (optional)
  // (colorSpace = GREY | SPECTRAL | METAL | NUCLEAR | RED | GREEN | BLUE)
  NSArray *prefs = [NSArray arrayWithObjects:@"colorSpace",@"symmetricWindow",nil];
  NSArray *values = [NSArray arrayWithObjects:[NSNumber numberWithInt:GREY],[NSNumber numberWithInt:NO],nil];
  NSMutableDictionary *displayPrefs = [NSMutableDictionary dictionaryWithObjects:values forKeys:prefs];
  [doc setDisplayInfo:displayPrefs];
  
  // Update processing history for this file
  NSMutableDictionary *procInfo = [NSMutableDictionary dictionary];
  [procInfo setObject:@"fmri_cluster_correlation" forKey:@"description"];
  
  NSMutableDictionary *settings = [NSMutableDictionary dictionary];
  if ([srcDocument fileName]!=nil) [settings setObject:[srcDocument fileName] forKey:@"Input Dataset"]; // Add name of input dataset
  [settings setObject:[NSNumber numberWithFloat:2.5] forKey:@"My Number"]; // This is how to add a numeric setting
  [settings setObject:@"Something" forKey:@"My String"]; // This is how to add a string setting
  [procInfo setObject:settings forKey:@"settings"];
  if ([srcDocument processingInfo]!=nil) [doc setProcessingInfo:[[srcDocument processingInfo] mutableCopy]]; // Copy processing history of input
  [[doc processingInfo] addObject:procInfo]; // Add present operation at end of the list
  
  if ([srcDocument acquisitionInfo]!=nil) [doc setAcquisitionInfo:[[srcDocument acquisitionInfo] mutableCopy]]; //Copy acquisition info of input
  if ([srcDocument demographicInfo]!=nil) [doc setDemographicInfo:[[srcDocument demographicInfo] mutableCopy]]; //Copy demographic info of input
	
  ///////////// End of file metadata configuration //////////////////////////////////////////
  
	// free memory
	free(currentVoxelTimeSeries);
	free(currentVoxelTimeSeries_zeroMean);
	free(ERB_ave);
	free(HRF);
	free(stat3);
	
  // Results must be returned as an array
  NSArray *results = [NSArray arrayWithObjects:doc,nil];
	
  return results;
  
}

@end
