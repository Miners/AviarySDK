//
//  AFPhotoEditorCustomization+FontAdditions.h
//  AviarySDK
//
//  Created by Michael Vitrano on 11/11/13.
//  Copyright (c) 2013 Aviary, Inc. All rights reserved.
//

#import "AFPhotoEditorCustomization.h"

@interface AFPhotoEditorCustomization (FontAdditions)

/*
 Configures the font file used in the Text tool

 @param name The name of the font contained in the font file.
 @param path The path to the .ttf font file
 @return Returns whether the font file was successfully imported.
 
*/

+ (BOOL)setTextToolFontWithName:(NSString *)name fontFileAtPath:(NSString *)path;

@end
