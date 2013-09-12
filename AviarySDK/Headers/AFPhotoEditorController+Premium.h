//
//  AFPhotoEditorController+Premium.h
//  AviarySDK
//
//  Created by Cameron Spickert on 8/15/12.
//  Copyright (c) 2012 Aviary, Inc. All rights reserved.
//

#import "AFPhotoEditorController.h"

extern NSString * const AFPhotoEditorControllerContentPackAvailabilityNotification;
extern NSString * const kAFPhotoEditorControllerContentPackAvailabiltyIdenfiter;

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

/**
 Use this method to determine whether a content pack is ready to be quick launched into.
 
 @param identifier The pack's Aviary identifier.
 @return Whether the pack is available for quick launch.
 */
+ (BOOL)contentPackAvailableForQuickLaunch:(NSString *)identifier;

/**
 Initialize the photo editor controller with an image. The editor will quick launch into
 the specified tool when presented. Currently, only Effects is supported. This method will return
 nil if any other key is passed in.
 
 @param image The image to edit.
 @param quickLaunchKey The tool to quick launch into.
 */
- (id)initWithImage:(UIImage *)image quickLaunchTool:(NSString *)quickLaunchKey;


@end
