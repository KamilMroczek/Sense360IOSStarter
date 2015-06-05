// Generated by Apple Swift version 1.2 (swiftlang-602.0.49.6 clang-602.0.49)
#pragma clang diagnostic push

#if defined(__has_include) && __has_include(<swift/objc-prologue.h>)
# include <swift/objc-prologue.h>
#endif

#pragma clang diagnostic ignored "-Wauto-import"
#include <objc/NSObject.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#if defined(__has_include) && __has_include(<uchar.h>)
# include <uchar.h>
#elif !defined(__cplusplus) || __cplusplus < 201103L
typedef uint_least16_t char16_t;
typedef uint_least32_t char32_t;
#endif

typedef struct _NSZone NSZone;

#if !defined(SWIFT_PASTE)
# define SWIFT_PASTE_HELPER(x, y) x##y
# define SWIFT_PASTE(x, y) SWIFT_PASTE_HELPER(x, y)
#endif
#if !defined(SWIFT_METATYPE)
# define SWIFT_METATYPE(X) Class
#endif

#if defined(__has_attribute) && __has_attribute(objc_runtime_name)
# define SWIFT_RUNTIME_NAME(X) __attribute__((objc_runtime_name(X)))
#else
# define SWIFT_RUNTIME_NAME(X)
#endif
#if !defined(SWIFT_CLASS_EXTRA)
# define SWIFT_CLASS_EXTRA
#endif
#if !defined(SWIFT_PROTOCOL_EXTRA)
# define SWIFT_PROTOCOL_EXTRA
#endif
#if !defined(SWIFT_ENUM_EXTRA)
# define SWIFT_ENUM_EXTRA
#endif
#if !defined(SWIFT_CLASS)
# if defined(__has_attribute) && __has_attribute(objc_subclassing_restricted) 
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) __attribute__((objc_subclassing_restricted)) SWIFT_CLASS_EXTRA
# else
#  define SWIFT_CLASS(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_CLASS_EXTRA
# endif
#endif

#if !defined(SWIFT_PROTOCOL)
# define SWIFT_PROTOCOL(SWIFT_NAME) SWIFT_RUNTIME_NAME(SWIFT_NAME) SWIFT_PROTOCOL_EXTRA
#endif

#if !defined(SWIFT_EXTENSION)
# define SWIFT_EXTENSION(M) SWIFT_PASTE(M##_Swift_, __LINE__)
#endif

#if !defined(OBJC_DESIGNATED_INITIALIZER)
# if defined(__has_attribute) && __has_attribute(objc_designated_initializer)
#  define OBJC_DESIGNATED_INITIALIZER __attribute__((objc_designated_initializer))
# else
#  define OBJC_DESIGNATED_INITIALIZER
# endif
#endif
#if !defined(SWIFT_ENUM)
# define SWIFT_ENUM(_type, _name) enum _name : _type _name; enum SWIFT_ENUM_EXTRA _name : _type
#endif
#if __has_feature(nullability)
#  define SWIFT_NULLABILITY(X) X
#else
# if !defined(__nonnull)
#  define __nonnull
# endif
# if !defined(__nullable)
#  define __nullable
# endif
# if !defined(__null_unspecified)
#  define __null_unspecified
# endif
#  define SWIFT_NULLABILITY(X)
#endif
#if defined(__has_feature) && __has_feature(modules)
@import CoreLocation;
@import ObjectiveC;
@import Foundation;
#endif

#pragma clang diagnostic ignored "-Wproperty-attribute-mismatch"
#pragma clang diagnostic ignored "-Wduplicate-method-arg"

@interface CLLocation (SWIFT_EXTENSION(SenseSdk))
@end

typedef SWIFT_ENUM(NSInteger, ConfidenceLevel) {
  ConfidenceLevelHigh = 3,
  ConfidenceLevelMedium = 2,
  ConfidenceLevelLow = 1,
  ConfidenceLevelUndetermined = 0,
};

enum CooldownTimeUnit : NSInteger;
@class SenseSdkErrorPointer;

SWIFT_CLASS("_TtC8SenseSdk8Cooldown")
@interface Cooldown

/// Default cooldown of 30 minutes
+ (Cooldown * __nonnull)defaultCooldown;
+ (Cooldown * __nullable)createWithOncePer:(NSInteger)oncePer frequency:(enum CooldownTimeUnit)frequency errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
@end

typedef SWIFT_ENUM(NSInteger, CooldownTimeUnit) {
  CooldownTimeUnitTesting = 0,
  CooldownTimeUnitMinutes = 60,
  CooldownTimeUnitHours = 3600,
  CooldownTimeUnitDays = 86400,
};

@class Location;
@class NSMutableDictionary;
enum PlaceType : NSInteger;
@protocol Region;

SWIFT_PROTOCOL("_TtP8SenseSdk5Place_")
@protocol Place <NSObject, NSCoding>
@property (nonatomic, readonly) Location * __nonnull location;
@property (nonatomic, readonly) double radius;
@property (nonatomic, readonly) NSMutableDictionary * __nonnull details;
@property (nonatomic, readonly, copy) NSString * __nonnull description;
@property (nonatomic, readonly) enum PlaceType type;
- (id <Region> __nonnull)getRegion;
@end

@class NSCoder;

SWIFT_CLASS("_TtC8SenseSdk14CustomGeofence")
@interface CustomGeofence : NSObject <NSCoding, Place>
@property (nonatomic, readonly) Location * __nonnull location;
@property (nonatomic, readonly) double radius;
@property (nonatomic, readonly, copy) NSString * __nonnull customIdentifier;
@property (nonatomic, readonly) enum PlaceType type;
@property (nonatomic, readonly) NSMutableDictionary * __nonnull details;
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude radius:(double)radius customIdentifier:(NSString * __nonnull)customIdentifier;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLocation:(Location * __nonnull)location radius:(double)radius customIdentifier:(NSString * __nonnull)customIdentifier OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)acoder;
- (id <Region> __nonnull)getRegion;
@end


SWIFT_CLASS("_TtC8SenseSdk21CustomGeofenceTrigger")
@interface CustomGeofenceTrigger : NSObject
@end

enum PoiType : NSInteger;
@class Trigger;
enum PersonalizedPlaceType : NSInteger;
@class NSNumber;

SWIFT_CLASS("_TtC8SenseSdk11FireTrigger")
@interface FireTrigger
+ (Trigger * __nullable)whenEntersPoi:(enum PoiType)type errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (Trigger * __nullable)whenExitsPoi:(enum PoiType)type errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (Trigger * __nullable)whenEntersPersonalizedPlace:(enum PersonalizedPlaceType)type errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (Trigger * __nullable)whenExitsPersonalizedPlace:(enum PersonalizedPlaceType)type kilometers:(NSNumber * __nullable)kilometers errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (Trigger * __nullable)whenEntersGeofences:(NSArray * __nonnull)geofences errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (Trigger * __nullable)whenExitsGeofences:(NSArray * __nonnull)geofences kilometers:(NSNumber * __nullable)kilometers errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
@end


SWIFT_CLASS("_TtC8SenseSdk8Location")
@interface Location : NSObject
@property (nonatomic, readonly) CLLocationDegrees latitude;
@property (nonatomic, readonly) CLLocationDegrees longitude;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLocation:(CLLocation * __nonnull)location OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)acoder;
- (CLLocationDistance)distanceFromLocation:(Location * __nonnull)loc;
- (CLLocationCoordinate2D)toCoordinate;
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;
- (CLLocationDistance)getDistance:(Location * __nonnull)other;
- (Location * __nonnull)addMetersToLatitude:(CLLocationDistance)distance;
- (Location * __nullable)getClosestLatLng:(NSArray * __nonnull)list;
@end


@interface NSArray (SWIFT_EXTENSION(SenseSdk))
@end


@interface NSDate (SWIFT_EXTENSION(SenseSdk))
@end


@interface NSFileManager (SWIFT_EXTENSION(SenseSdk))
@end


@interface NSNumber (SWIFT_EXTENSION(SenseSdk))
@end


@interface NSUserDefaults (SWIFT_EXTENSION(SenseSdk))
@end


SWIFT_CLASS("_TtC8SenseSdk17PersonalizedPlace")
@interface PersonalizedPlace : NSObject <NSCoding, Place>
@property (nonatomic, readonly) Location * __nonnull location;
@property (nonatomic, readonly) double radius;
@property (nonatomic, readonly) enum PersonalizedPlaceType personalizedPlaceType;
@property (nonatomic, readonly) enum PlaceType type;
@property (nonatomic, readonly) NSMutableDictionary * __nonnull details;
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLatitude:(CLLocationDegrees)latitude longitude:(CLLocationDegrees)longitude radius:(double)radius personalizedPlaceType:(enum PersonalizedPlaceType)personalizedPlaceType;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithLocation:(Location * __nonnull)location radius:(double)radius personalizedPlaceType:(enum PersonalizedPlaceType)personalizedPlaceType OBJC_DESIGNATED_INITIALIZER;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)acoder;
- (id <Region> __nonnull)getRegion;
@end


SWIFT_CLASS("_TtC8SenseSdk24PersonalizedPlaceTrigger")
@interface PersonalizedPlaceTrigger : NSObject
@end

typedef SWIFT_ENUM(NSInteger, PersonalizedPlaceType) {
  PersonalizedPlaceTypeHome = 1,
  PersonalizedPlaceTypeWork = 2,
};


typedef SWIFT_ENUM(NSInteger, PlaceType) {
  PlaceTypePersonal = 1,
  PlaceTypeCustomGeofence = 2,
  PlaceTypePoi = 3,
};


SWIFT_CLASS("_TtC8SenseSdk8PoiPlace")
@interface PoiPlace : NSObject <NSCoding, Place>
@property (nonatomic, readonly, copy) NSString * __nonnull id;
@property (nonatomic, readonly) Location * __nonnull location;
@property (nonatomic, readonly) double radius;
@property (nonatomic, readonly) enum PlaceType type;
@property (nonatomic, readonly) NSMutableDictionary * __nonnull details;
@property (nonatomic, readonly, copy, getter=description) NSString * __nonnull description;
- (CLLocationDistance)distanceFrom:(Location * __nonnull)other;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithCoder:(NSCoder * __nonnull)aDecoder;
- (void)encodeWithCoder:(NSCoder * __nonnull)acoder;
- (id <Region> __nonnull)getRegion;
@end


SWIFT_CLASS("_TtC8SenseSdk10PoiTrigger")
@interface PoiTrigger : NSObject
@end

typedef SWIFT_ENUM(NSInteger, PoiType) {
  PoiTypeAirport = 1,
  PoiTypeBar = 2,
  PoiTypeRestaurant = 3,
  PoiTypeMall = 4,
  PoiTypeCafe = 5,
  PoiTypeGym = 6,
  PoiTypeUnknown = 9999,
};

@class TimeWindow;

SWIFT_CLASS("_TtC8SenseSdk6Recipe")
@interface Recipe : NSObject
@property (nonatomic, readonly, copy) NSString * __nonnull name;
@property (nonatomic, readonly) Trigger * __nonnull trigger;
@property (nonatomic, readonly) TimeWindow * __nonnull timeWindow;
@property (nonatomic, readonly) Cooldown * __nonnull cooldown;
- (SWIFT_NULLABILITY(nonnull) instancetype)initWithName:(NSString * __nonnull)name trigger:(Trigger * __nonnull)trigger timeWindow:(TimeWindow * __nonnull)timeWindow cooldown:(Cooldown * __nonnull)cooldown OBJC_DESIGNATED_INITIALIZER;
@end

@class TriggerFiredArgs;

SWIFT_CLASS("_TtC8SenseSdk15RecipeFiredArgs")
@interface RecipeFiredArgs
@property (nonatomic, readonly) NSDate * __nonnull timestamp;
@property (nonatomic, readonly) Recipe * __nonnull recipe;
@property (nonatomic, readonly) enum ConfidenceLevel confidenceLevel;
@property (nonatomic, readonly, copy) NSArray * __nonnull triggersFired;
@end


SWIFT_PROTOCOL("_TtP8SenseSdk19RecipeFiredDelegate_")
@protocol RecipeFiredDelegate
- (void)recipeFired:(RecipeFiredArgs * __nonnull)args;
@end


SWIFT_PROTOCOL("_TtP8SenseSdk6Region_")
@protocol Region
- (BOOL)overlaps:(Location * __nonnull)otherLocation;
- (id <Region> __nonnull)addRadiusWithRadius:(NSNumber * __nonnull)radius;
@end


SWIFT_CLASS("_TtC8SenseSdk8SenseSdk")
@interface SenseSdk
+ (void)enableSdkWithKey:(NSString * __nonnull)apiKey;
+ (BOOL)registerWithRecipe:(Recipe * __nonnull)recipe delegate:(id <RecipeFiredDelegate> __nonnull)delegate errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
+ (BOOL)unregisterWithName:(NSString * __nonnull)name;
+ (Recipe * __nullable)findRecipeWithName:(NSString * __nonnull)name;
@end


SWIFT_CLASS("_TtC8SenseSdk13SenseSdkError")
@interface SenseSdkError
@property (nonatomic, readonly, copy) NSString * __nonnull message;
@end


SWIFT_CLASS("_TtC8SenseSdk20SenseSdkErrorPointer")
@interface SenseSdkErrorPointer
@property (nonatomic, readonly) SenseSdkError * __null_unspecified error;
+ (SenseSdkErrorPointer * __nonnull)create;
@end


SWIFT_CLASS("_TtC8SenseSdk19SenseSdkTestUtility")
@interface SenseSdkTestUtility
+ (BOOL)fireTriggerFromRecipe:(NSString * __nonnull)name confidenceLevel:(enum ConfidenceLevel)confidenceLevel places:(NSArray * __nonnull)places errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
@end


SWIFT_CLASS("_TtC8SenseSdk10TimeWindow")
@interface TimeWindow
@property (nonatomic, readonly) NSInteger from;
@property (nonatomic, readonly) NSInteger to;

/// Default window of the entire day
+ (TimeWindow * __nonnull)allDay;
+ (TimeWindow * __nullable)createFromHour:(NSInteger)fromHour toHour:(NSInteger)toHour errorPtr:(SenseSdkErrorPointer * __nullable)errorPtr;
@end

enum TriggerType : NSInteger;

SWIFT_CLASS("_TtC8SenseSdk7Trigger")
@interface Trigger
@property (nonatomic, readonly) enum TriggerType triggerType;
@end


SWIFT_CLASS("_TtC8SenseSdk16TriggerFiredArgs")
@interface TriggerFiredArgs
@property (nonatomic, readonly) NSDate * __nonnull timestamp;
@property (nonatomic, readonly, copy) NSArray * __nonnull places;
@property (nonatomic, readonly) enum ConfidenceLevel confidenceLevel;
@end

typedef SWIFT_ENUM(NSInteger, TriggerType) {
  TriggerTypePersonal = 1,
  TriggerTypeCustomGeofence = 2,
  TriggerTypePoi = 3,
};

#pragma clang diagnostic pop
