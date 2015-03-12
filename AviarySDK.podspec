Pod::Spec.new do |s|
  s.name                = 'AviarySDK'
  s.version             = '4.4.5'
  s.summary             = "Aviary's photo editing SDK for iOS."
  s.homepage            = 'http://developers.aviary.com/docs/ios'
  s.license             = {
	:type => 'Commercial',
	:text => <<-LICENSE
	  Copyright (c) 2014 Aviary, Inc. All rights reserved.
	  LICENSE
  }
  s.author              = { 'Aviary, Inc.' => 'api@aviary.com' }
  social_media_url      = 'https://twitter.com/Aviary'
  s.source              = { :http => 'http://aviarystatic.s3.amazonaws.com/sdk/ios/4.4.5/Aviary-iOS-SDK.zip' }
  s.platform            = :ios, '6.0'
  s.resource            = 'AviarySDK-4.4.5/AviarySDK/AviarySDKResources.bundle'
  s.vendored_frameworks = 'AviarySDK-4.4.5/AviarySDK/AviarySDK.framework'
  s.frameworks          = 'QuartzCore', 'Accelerate', 'StoreKit', 'CoreData', 'MessageUI', 'OpenGLES'
  s.libraries           = 'z', 'sqlite3'
  s.requires_arc        = true
end
