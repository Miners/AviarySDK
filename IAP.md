# In-app Purchase

The iOS SDK now includes the ability to provide content packs for purchase within the Effects tool via the StoreKit framework. This guide will show you how to enable and properly use this feature.

This guide assumes familiarity with the StoreKit framework and enabling in-app purchase for your app in iTunes Connect. For more information on the basic setup process, please see [Apple's developer site](http://developer.apple.com).

## iTunes Connect

Before you start coding, you will need to register the following in-app purchase product information in iTunes Connect (choose the *non-consumable* product option):

	Name: Grunge
	Description: Add some grit and visual wear-and-tear to your photos with these six grungy effects.
	Identifier: com.<your_domain>.effectpack.01
	
	Name: Nostalgia
	Description: Reminisce over fond memories and good times with our six dreamy nostalgia effects.
	Identifier: com.<your_domain>.effectpack.02
	
We recommend filling in the "Name" and "Description" fields exactly as listed above to ensure App Store approval. The product identifier templates listed above are optional--you may register whatever product identifier you like. Make a note of these identifiers, as you will need them later in this guide.

## Configuring your app

You should have access to the following files:

	AFPhotoEditorController+InAppPurchase.h
	AFPhotoEditorProduct.h
	
These files provide an interface to classes, methods and protocols that will allow you to enable in-app purchase for your users.

0. Import the header files above in your app delegate's implementation file.

1. Add the following lines to your app delegate's `-applicationFinishedLaunchingWithOptions:` method *before* invoking any StoreKit framework methods:
	
		[[AFPhotoEditorController inAppPurchaseManager] setDelegate:self];
		[[AFPhotoEditorController inAppPurchaseManager] startObservingTransactions];
	
	The first line will set your app delegate to receive callbacks from our in-app purchase manager singleton object, which is returned by the `+inAppPurchaseManager` class method of `AFPhotoEditorController`. In order for this to work properly, implement the `AFInAppPurchaseManagerDelegate` protocol in your app delegate (see below, and take a look at the inline documentation in `AFPhotoEditorController+InAppPurchase.h` for more information).
	
	The second line adds the in-app purchase manager singleton as an observer of the StoreKit payment queue returned by `[SKPaymentQueue defaultQueue]`, and sets a flag enabling in-app purchase code throughout the SDK.
	
2. Implement the `AFInAppPurchaseManagerDelegate` protocol in your app delegate. This protocol allows you to provide your own globally unique product identifiers for our content packs. The identifiers you provide via this protocol should match the information you entered into iTunes Connect for each product.

	Here is a sample implementation of the `-inAppPurchaseManager:productIdentifierForProduct:` delegate method:
	
		- (NSString *)inAppPurchaseManager:(id<AFInAppPurchaseManager>)manager productIdentifierForProduct:(AFPhotoEditorProduct *)product
		{
			NSString *internalID = [product internalProductIdentifier];
			if ([internalID isEqualToString:kAFProductEffectsGrunge]) {
				return @"com.mycompany.effectpack.01";
			}
			if ([internalID isEqualToString:kAFProductEffectsNostalgia]) {
				return @"com.mycompany.effectpack.02";
			}
			return internalID;
		}
	
	The product constants referenced above are defined in `AFPhotoEditorProduct.h`.
	
3. After you have configured your app delegate for in-app purchase, you can create and present an `AFPhotoEditorController` instance by following the usual procedure and documentation, with one caveat. We have added the following additional option (declared in `AFPhotoEditorController+InAppPurchase.h` that must be passed to the editor instance on initialization to enable in-app purchase:

		kAFPhotoEditorEffectsIAPEnabledKey
		
	To enable Effect pack in-app purchases, pass `[NSNumber numberWithBool:YES]` or `kCFBooleanTrue` as the value for this key. See `AFPhotoEditorController.h` and `AFPhotoEditorControllerOptions.h` for more information about how to pass options to a new photo editor instance.
	
## Testing

We recommend that you test the SDK thoroughly before deploying to the app store. This involves the usual StoreKit testing process of creating test user accounts in iTunes Connect and making purchases in the sandbox environment.

If you have any questions or comments, or run into any problems implementing in-app purchase, please contact us at api@aviary.com.
