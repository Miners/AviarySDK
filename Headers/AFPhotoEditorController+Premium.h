//
//  AFPhotoEditorController+Premium.h
//  AviarySDK
//
//  Created by Cameron Spickert on 8/15/12.
//  Copyright (c) 2012 Aviary, Inc. All rights reserved.
//

#import "AFPhotoEditorController.h"

@interface AFPhotoEditorController (Premium)

/**
 Get the value of the boolean indicating whether the user's hashed UDID is being used in Aviary's analytics.
 */
+ (BOOL)useHashedUDIDForAnalytics;

/**
 Set the value of the boolean indicating whether the user's hashed UDID should be used in Aviary's analytics.
 
 @param use BOOL indicating whether the hashed UDID should be used.
 */
+ (void)setUseHashedUDIDForAnalytics:(BOOL)use;

@end
