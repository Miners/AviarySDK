//
//  AFPhotoEditorController+InAppPurchase.h
//  AviarySDK
//
//  Copyright (c) 2012 Aviary, Inc. All rights reserved.
//

#import "AFPhotoEditorController.h"
#import "AFPhotoEditorProduct.h"

/** @addtogroup AFPhotoEditorControllerOptions
    @{
 */

/**
    This key controls the availability of non-consumable in-app purchases in the
    Effects tool. A valid value for this key is a boolean NSNumber (or
    kCFBoolean{True, False}). Pass YES or kCFBooleanTrue to enable in-app purchase
    for effects. This option is disabled by default.
 */
extern NSString *const kAFPhotoEditorEffectsIAPEnabledKey;

/** @} */

@protocol AFInAppPurchaseManager;
@protocol AFInAppPurchaseManagerDelegate;

@interface AFPhotoEditorController (InAppPurchase)

/**
    The handler object for purchasing consumable content. In order for in-app
    purchase to function correctly, you must add the object returned by this method
    as an observer of the default SKPaymentQueue. In your app delegate's
    -finishedLaunchingWithOptions: method, you should include the following line:

    [[AFPhotoEditorController inAppPurchaseManager] startObservingTransactions];

    Please see README.md for more information about in-app purchases.

    @see AFInAppPurchaseManager (startObservingTransactions,
    stopObservingTransactions)
    @see AFPhotoEditorControllerOptions.h
    @see kAFPhotoEditorEffectsIAPEnabledKey
 */
+ (id<AFInAppPurchaseManager>)inAppPurchaseManager;

@end

@protocol AFInAppPurchaseManagerDelegate <NSObject>
@optional

/**
    If implemented by the photo editor's delegate, this method will be called
    just before requesting information about products available through in-app
    purchase via the StoreKit API. This method should return the product
    identifier registered in iTunes Connect for the provided product.
    
    @param product The product for which to return the product identifier
    registered in iTunes Connect.
    @returns The product identifier registered in iTunes Connect.
 
    @see AFPhotoEditorProduct
 */
- (NSString *)inAppPurchaseManager:(id<AFInAppPurchaseManager>)manager productIdentifierForProduct:(AFPhotoEditorProduct *)product;

@end

/**
    This protocol is implemented by the object returned by
    [AFPhotoEditorController inAppPurchaseManager]. You should call these
    methods to activate and deactivate in-app purchase.

    @see AFPhotoEditorController (inAppPurchaseManager)
 */
@protocol AFInAppPurchaseManager <NSObject>

/**
    A delegate for handling in-app purchase-related callbacks, including mapping
    internal product identifiers to developer-provided identifiers registered in
    iTunes Connect.
 
    @see AFInAppPurchaseManagerDelegate
 */
@property (nonatomic, assign) id<AFInAppPurchaseManagerDelegate> delegate;

/**
    @returns YES if the in-app purchase manager is observing transactions (in-app
    purchase is enabled), NO otherwise.
 */
@property (nonatomic, assign, readonly, getter=isObservingTransactions) BOOL observingTransactions;

/**
    Call this method to start observing transactions. After calling this method,
    isObservingTransactions will return YES.
 */
- (void)startObservingTransactions;

/**
    Call this method to stop observing transactions. After calling this method,
    isObservingTransactions will return NO.
 */
- (void)stopObservingTransactions;

@end
