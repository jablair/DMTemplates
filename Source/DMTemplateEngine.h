
// DMTemplateEngine.h
// by Dustin Mierau
// Cared for under the MIT license.

@class DMTemplateCondition;

@interface DMTemplateEngine : NSObject {
@private
	NSString *template;
	NSString *beginProcessorMarker;
	NSString *endProcessorMarker;
	
	id object;
	NSMutableArray *conditionStack;
	NSMutableDictionary *modifiers;
	NSScanner *scanner;
	NSMutableString *renderedTemplate;
	DMTemplateCondition *currentCondition;
	BOOL hasCondition;
	BOOL overallCondition;
}

@property (nonatomic, retain) NSString* template;
@property (nonatomic, retain) NSString* beginProcessorMarker; // Default: <?
@property (nonatomic, retain) NSString* endProcessorMarker; // Default: />

+ (id)engine;
+ (id)engineWithTemplate:(NSString*)string;

// Render
- (NSString*)renderAgainst:(id)object;

// Modifiers
- (void)addModifier:(unichar)modifier block:(NSString*(^)(NSString*))block;
- (void)removeModifier:(unichar)modifier;
- (void)removeAllModifiers;

@end