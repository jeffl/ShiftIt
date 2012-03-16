//
//  WindowContext.h
//  ShiftIt
//
//  Created by Filip Krikava on 9/1/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ShiftIt.h"

typedef void* SIWindowRef;
typedef void* SIWindowsRef;

@interface SIScreen : NSObject {
@private
	NSRect visibleRect_;
	NSRect screenRect_;
	BOOL primary_;
}

@property (readonly) NSSize size;
@property (readonly) BOOL primary;

+ (SIScreen *) screenFromNSScreen:(NSScreen *)screen;

- (id) initWithNSScreen:(NSScreen *)screen;

@end

@interface SIWindow : NSObject {
@private	
    SIWindowRef ref_;
    NSRect windowRect_;
    NSRect drawersRect_;
    NSRect geometry_;
    SIScreen *screen_;
}

@property (readonly) NSRect geometry;
@property (readonly) NSPoint origin;
@property (readonly) NSSize size;
@property (readonly) SIScreen *screen;

@end


@interface SIWindows : NSArray {
@private	
    SIWindowsRef ref_;
    SIScreen *screen_;
}

@property (readonly) SIScreen *screen;

@end



@protocol WindowContext <NSObject>

- (BOOL) getAllWindows:(SIWindows **)windows error:(NSError **)error;

- (BOOL) getFocusedWindow:(SIWindow **)window error:(NSError **)error;

- (BOOL) setWindow:(SIWindow *)window geometry:(NSRect)geometry error:(NSError **)error;

- (BOOL) toggleZoomOnWindow:(SIWindow *)window error:(NSError **)error;

- (BOOL) toggleFullScreenOnWindow:(SIWindow *)window error:(NSError **)error;

@end
