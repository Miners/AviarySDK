//
//  AFPhotoEditorStyle+Premium.h
//  AviarySDK
//
//  Created by Cameron Spickert on 8/15/12.
//  Copyright (c) 2012 Aviary, Inc. All rights reserved.
//

#import "AFPhotoEditorStyle.h"

@interface AFPhotoEditorStyle (Premium)

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.navigationBarBackgroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *topBarBackgroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.bottomBarBackgroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *bottomBarBackgroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.applyButtonBackgroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *applyButtonBackgroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.applyButtonStrokeColor" as the key.
 */
@property (nonatomic, strong) UIColor *applyButtonStrokeColor;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.cancelButtonBackgroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *cancelButtonBackgroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.cancelButtonStrokeColor" as the key.
 */
@property (nonatomic, strong) UIColor *cancelButtonStrokeColor;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.backButtonBackgroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *backButtonBackgroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.backButtonStrokeColor" as the key.
 */
@property (nonatomic, strong) UIColor *backButtonStrokeColor;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.backButtonForegroundImage" as the key.
 */
@property (nonatomic, strong) UIImage *backButtonForegroundImage;

/**
 Deprecated.
 
 Instead, you may set this value by calling [AFPhotoEditorCustomization setOptionValue:forKey:] with the desired color as the option value and @"editor.tool.crop.cellWidth" as the key.
 */
@property (nonatomic, assign) CGFloat cropCellWidth;

@end
