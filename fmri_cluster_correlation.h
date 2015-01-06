//
//  fmri_cluster_correlation.h
//  fmri_cluster_correlation
//
//  Created by crossley on 11/30/10.
//  Copyright __MyCompanyName__ 2010 . All rights reserved.
//

#import <Cocoa/Cocoa.h>
#import <NLPlugin/NLPlugin.h>
#import <math.h>
#import <vecLib/vecLib.h>
#import <stdio.h>
#import <stdlib.h>

@interface fmri_cluster_correlation : NLPlugin {

  // Parameters that describe settings for the processing operations are defined here
	int* ev_ind;
	int num_evs;
	int ev_length;
	
	NSString *filePath;
	
	float* currentVoxelTimeSeries;
	float* currentVoxelTimeSeries_zeroMean;
	float currentVoxelTimeSeriesMean;
	
	float ERB_rms;
	float HRF_ERB;
	
	float* HRF;
	float* ERB_ave;
	
	float* stat3;
}

// Objective-C methods for your custom subclass are defined here

@end
