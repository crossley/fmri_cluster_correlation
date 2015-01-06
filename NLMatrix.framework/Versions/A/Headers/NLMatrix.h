//
//  NLMatrix.h
//  NeuroLens
//
//  Created by Rick Hoge on Wed May 19 2004.
//  Copyright (c) 2004 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Accelerate/Accelerate.h>

// This is a class for Matrix objects, including wrappers for
// BLAS and LAPACK functions and also providing some Matlab-like functionality
// Note that data is stored in column major order, for compatibility
// with Matlab algorithms and BLAS/LAPACK's Fortran roots
//
// This means that CONTIGUOUS BYTES FORM COLUMNS!!!
//
//


@interface NLMatrix : NSObject <NSCoding, NSCopying> {

  NSMutableData *theData;
  
  long numRows;
  long numColumns;
  
}

-(id)initWithBytes:(void *)bytes rows:(long)rows columns:(long)columns;
-(id)initWithMatrix:(NLMatrix*)matrix;
+(id)matrixWithBytes:(void *)bytes rows:(long)rows columns:(long)columns;
+(id)matrixWithMatrix:(NLMatrix *)matrix;
-(id)copy;

  // These create a new matrix (autoreleased)
+(NLMatrix *)toeplitzWithRow:(NLMatrix *)row;
+(NLMatrix *)toeplitzWithRow:(NLMatrix *)row column:(NLMatrix *)column;
+(NLMatrix *)identityMatrixWithOrder:(long)order;
+(NLMatrix *)productOfMatrices:(NSArray *)matrices;
+(NLMatrix *)onesWithRows:(long)rows columns:(long)columns;
+(NLMatrix *)zerosWithRows:(long)rows columns:(long)columns;
+(NLMatrix*)countFrom:(int)start to:(int)end; // Generate range of consecutive integers

  // These return a new matrix (autoreleased)
-(NLMatrix *)plus:(NLMatrix *)matrix2; // Add two matrices
-(NLMatrix *)minus:(NLMatrix *)matrix2; // subtract two matrices
-(NLMatrix *)mTimes:(NLMatrix *)matrix2; // Matrix multiply
-(NLMatrix *)sTimes:(NLMatrix *)matrix2; // Scalar multiply two matrices
// -(NLMatrix *)mDiv:(NLMatrix *)matrix2; // Matrix divide - not defined; use inverse
-(NLMatrix *)sDiv:(NLMatrix *)matrix2; // Scalar divide two matrices
-(NLMatrix *)multByScalar:(float)factor; // Scalar multiply a matrix by a scalar
-(NLMatrix *)divByScalar:(float)factor; // Scalar divide a matrix by a scalar
-(NLMatrix *)addScalar:(float)value; // Add a scalar to every element in a matrix
-(NLMatrix *)subScalar:(float)value; // Subtract a scalar from every element in a matrix

-(NLMatrix *)appendPolyOfOrder:(int)order; // Append polynomial basis functions as columns
+(NLMatrix *)polyOfOrder:(int)order rows:(int)rows;
-(NLMatrix *)appendColumns:(NLMatrix *)matrix2; // Append columns to a matrix
-(void)appendColumnsInPlace:(NLMatrix *)matrix2; // Append columns to a matrix in place
  // These use zero-based indexing
-(NLMatrix *)replaceRows:(NLMatrix *)rows withScalar:(float)val; // Replace rows with a scalar value (e.g. zero)
-(NLMatrix *)replaceColumns:(NLMatrix *)columns withScalar:(float)val; // Replace columns with a scalar value (e.g. zero)
  //-(NLMatrix *)extractRow:(int)row; // Return a single row of a matrix
-(NLMatrix *)extractColumn:(int)column; // Return a single column of a matrix
-(NLMatrix *)extractColumnsInRange:(NSRange)range;
-(NLMatrix *)extractRowsInRange:(NSRange)range;
-(NLMatrix *)reshapeToRows:(int)rows columns:(int)columns; // Reshape matrix to be rows x columns - number of elements must not change
  // Elements are taken columnwise so buffer organization will not change
-(NLMatrix*)extractRows:(NLMatrix*)rows columns:(NLMatrix*)columns;

-(NLMatrix*)transpose; // Transpose the receiver
-(NLMatrix*)diag; // Return matrix with vector values along diagonal
-(NLMatrix*)inverse; // Compute matrix inverse of receiver
-(NLMatrix*)pinv; // Pseudo-inverse of receiver
-(NLMatrix*)cholesky; // Cholesky factorization
-(NSArray*)svd; // Singular-value decomposition of receiver - returns NSArray of NLMatrix objects
-(NSArray*)eigs; // Eigenvalues and eigenvectors for upper symmetric matrix.  Returns NSArray of NLMatrix objects
-(NSArray*)eig; // Eigenvalues and eigenvectors for non-symmetric square matrix.  Returns NSArray of NLMatrix objects
-(NSArray*)sort; // Sort a matrix
-(float)trace; // Trace of receiver
-(int)rank; // Rank of the receiver
-(float)sum; // Sum of all elements
-(float)min; // Minimum of all elements
-(float)max; // Maximum of all elements

-(NLMatrix *)sumColumns; // Sum every column > produces a single row
-(NLMatrix *)sumRows; // Sum every row > produces a single column
-(NLMatrix *)minColumns; // Min in each column > produces a single row
-(NLMatrix *)maxColumns; // Max in each column > produces a single row
-(NLMatrix *)stdColumns; // Standard deviation of each column > produces a single row
-(NLMatrix *)medianColumns; // Compute median of every column > produces a single row
-(NLMatrix *)sqrt; // Take square root elementwise
-(NLMatrix *)reciprocal; // 1/receiver, elementwise
-(NLMatrix *)pow:(float)power; // Raise elements to power
-(NLMatrix *)squared; // Square elements of receiver
-(NLMatrix *)exp; // Raise e to power of elements
-(NLMatrix*)log10; // Log 10 of elements
-(NLMatrix*)abs; // Absolute value of elements
-(NLMatrix*)sign; // Sign of elements
-(NLMatrix *)mPow:(NLMatrix *)matrix2; // Raise elements to power of elements in another matrix
-(int)setNansTo:(float)value; // Replace Nan's in receiver with value

// Spatial Transformation Methods
+(NLMatrix*)matrixFromDx:(float)dx dy:(float)dy dz:(float)dz 
                  thetaX:(float)thx thetaY:(float)thy thetaZ:(float)thz
                  shearX:(float)shx shearY:(float)shy shearZ:(float)shz
                   scale:(float)s scaleX:(float)sx scaleY:(float)sy scaleZ:(float)sz
                 xcenter:(float)cx ycenter:(float)cy zcenter:(float)cz;

// Stuff for computing p values
-(NLMatrix*)logtcdf_dof:(long double)dof;

+(NLMatrix *)matrixFromString:(NSString *)theString; // Returns a row vector
-(void)print; // Display value

  // Accessors
-(NSMutableData*)theData;
-(NSMutableData*)theDataAsDouble;
-(NSMutableData*)theDataAsLongDouble;
-(void)setTheData:(NSMutableData*)data;
-(long)numRows;
-(void)setNumRows:(long)value;
-(long)numColumns;
-(void)setNumColumns:(long)value;
-(void*)bytes;

@end
