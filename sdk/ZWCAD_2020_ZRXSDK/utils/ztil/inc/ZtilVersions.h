#ifndef  ZTILVERSIONS_H
#define  ZTILVERSIONS_H

/// <summary>
/// The public classes, those in the export /inc folder that are exposed by 
/// ZTIL.lib library constitute an API for applications. That API is versioned
/// by the defines below. This version number doubles as a version number for
/// the ZTIL.lib library itself. 
/// </summary>
///
/// <remarks>
/// The Minor version below is incremented for:
/// 1) The addition of new classes being defined
/// 2) Special cases of binary compatible API additions to existing classes (methods)
/// 3) Major changes of internal logic while maintaining the API. These changes
///    may change implementation behavior while not changing the published usage.
///    This could be interpreted as a warning not to depend on implementation 
///    side effects of ZTIL objects. 
///
/// The Major version is incremented when a change is made that renders previous
/// versions of the client api incompatible with the new release of the ZTIL. It
/// means that applications will/may need to "port" their application including
/// binary or API incompatibility.
/// </remarks>
///
#define ZTILIMAGEAPIMAJORVERSION "1"
#define ZTILIMAGEAPIMIMORVERSION "0"

/// <summary>
/// API versions are dictated by these defines located in the ZTIL library.
/// When ZTIL is built and released, the internal interfaces to the subsystems
/// define these as part of their build string sentinels. This allows checking
/// of ZTILImp(ST/MT/98) libraries for API compatability with the ZTIL.lib core.
/// </summary>
///
/// <remarks>
/// The Minor version below is incremented for:
/// 1) The addition of new classes such that older subsystems remain compatible. (rare)
///    **This would mean that a "refusal" method would be needed to deny
///    the new class support.
///
/// The Major version is incremented when a change is made that renders previous
/// versions of the implementation subsystems incompatible with the new release 
/// of ZTIL.
///
/// NOTE:: Although this versioning provides a degree of safety when mixing
/// implementation libraries with different versions of the ZTIL core library,
/// such is NOT recommended. The ZTILImp library released with the ZTIL library
/// are meant to be a matched pair.
/// </remarks>
///
#define ZTILSUBSYSTEMAPIMAJORVERSION "1"
#define ZTILSUBSYSTEMAPIMINORVERSION "0"

/// <summary>
/// API versions are dictated by these defines located in the ZTIL library.
/// When ZTIL is built and released, all included format codecs use these 
/// defines as part of their build string sentinels. Then each codec returns
/// an instance of a custom derived class(FormatCodecApiVersion) that returned
/// to and used by ZTIL to test compatibility with a codec before registering it
/// for use with ZTIL.
///
/// By using a derived class, some custom implementation is possible that may
/// allow a codec to be compatible with more than one version of the API.
/// </summary>
///
/// <remarks>
/// The Minor version below is incremented for:
/// 1) The addition of new property types being defined
/// 2) Special cases of binary compatible API additions (methods)
/// 3) Major changes of internal logic while maintaining the API. These changes
///    may change implementation behavior while not changing the published usage.
///    This could be interpreted as a warning not to depend on implementation 
///    side effects of ZTIL objects. 
///
/// The Major version is incremented when a change is made that renders previous
/// versions of the format codecs incompatible with the new release of the ZTIL
/// communication system of API classes.
/// </remarks>
///
#define ZTILFORMATCODECAPIMAJORVERSION "1"
#define ZTILFORMATCODECAPIMINORVERSION "0"

#endif
