//
//  TLTagsControl.h
//  TagsInputSample
//
//  Created by Антон Кузнецов on 11.02.15.
//  Copyright (c) 2015 TheLightPrjg. All rights reserved.
//

#import <UIKit/UIKit.h>

@class TLTagsControl;

@protocol TLTagsControlDelegate <NSObject>

@required

- (void)tagsControl:(TLTagsControl *)tagsControl tappedAtIndex:(NSInteger)index;

@optional

- (void)tagsControl:(TLTagsControl *)tagsControl didAddTag:(NSString *)tag;

- (void)tagsControl:(TLTagsControl *)tagsControl didRemoveTag:(NSString *)tag;

@end

typedef NS_ENUM(NSUInteger, TLTagsControlMode) {
    TLTagsControlModeEdit,
    TLTagsControlModeList,
};

@interface TLTagsControl : UIScrollView

@property (nonatomic, strong) NSMutableArray *tags;
@property (nonatomic, strong) UIColor *tagsBackgroundColor;
@property (nonatomic, strong) UIColor *tagsTextColor;
@property (nonatomic, strong) UIColor *tagsDeleteButtonColor;
@property (nonatomic, strong) NSString *tagPlaceholder;
@property (nonatomic) TLTagsControlMode mode;

@property (nonatomic, strong) UIFont *tagsPlaceholderFont;

@property (assign, nonatomic) id<TLTagsControlDelegate> tapDelegate;

- (id)initWithFrame:(CGRect)frame andTags:(NSArray *)tags withTagsControlMode:(TLTagsControlMode)mode;

- (void)addTag:(NSString *)tag;
- (void)reloadTagSubviews;

@end