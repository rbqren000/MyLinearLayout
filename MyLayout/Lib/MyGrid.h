//
//  MyGrid.h
//  MyLayout
//
//  Created by oubaiquan on 2017/8/23.
//  Copyright © 2017年 YoungSoft. All rights reserved.
//

#import "MyLayoutDef.h"
#import "MyBorderline.h"


extern NSString * const kMyGridRows;
extern NSString * const kMyGridCols;
extern NSString * const kMyGridSize;
extern NSString * const kMyGridPadding;
extern NSString * const kMyGridSpace;
extern NSString * const kMyGridGravity;
extern NSString * const kMyGridPlaceholder;
extern NSString * const kMyGridTopBorderline;
extern NSString * const kMyGridBottomBorderline;
extern NSString * const kMyGridLeftBorderline;
extern NSString * const kMyGridRightBorderline;

extern NSString * const kMyGridBorderlineColor;
extern NSString * const kMyGridBorderlineThick;
extern NSString * const kMyGridBorderlineHeadIndent;
extern NSString * const kMyGridBorderlineTailIndent;
extern NSString * const kMyGridBorderlineOffset;


extern NSString * const vMyGridSizeWrap;
extern NSString * const vMyGridSizeFill;


extern NSString * const vMyGridGravityTop;
extern NSString * const vMyGridGravityBottom;
extern NSString * const vMyGridGravityLeft;
extern NSString * const vMyGridGravityRight;
extern NSString * const vMyGridGravityCenterX;
extern NSString * const vMyGridGravityCenterY;
extern NSString * const vMyGridGravityWidthFill;
extern NSString * const vMyGridGravityHeightFill;





/**
 栅格协议。用来描述栅格块，以及栅格的添加和删除。
 */
@protocol MyGrid <NSObject>


/**
 添加行栅格，返回新的栅格。其中的measure可以设置如下的值：
 1.大于等于1的常数，表示固定尺寸。
 2.大于0小于1的常数，表示占用整体尺寸的比例
 3.小于0大于-1的常数，表示占用剩余尺寸的比例
 4.MyLayoutSize.wrap 表示尺寸由子栅格包裹
 5.MyLayoutSize.fill 表示占用栅格剩余的尺寸
 */
-(id<MyGrid>)addRow:(CGFloat)measure;

//添加列栅格，返回新的栅格。
-(id<MyGrid>)addCol:(CGFloat)measure;

//添加栅格，返回被添加的栅格。这个方法和下面的cloneGrid配合使用可以用来构建那些需要重复添加栅格的场景。
-(id<MyGrid>)addRowGrid:(id<MyGrid>)grid;
-(id<MyGrid>)addColGrid:(id<MyGrid>)grid;

//克隆出一个新栅格以及其下的所有子栅格。
-(id<MyGrid>)cloneGrid;

//从父栅格中删除。
-(void)removeFromSuperGrid;

//得到父栅格。
-(id<MyGrid>)superGrid;

//得到所有子栅格
-(NSArray<id<MyGrid>> *)subGrids;


//栅格内子栅格之间的间距
@property(nonatomic, assign) CGFloat subviewSpace;

//栅格内子栅格或者叶子栅格内视图的四周内边距。
@property(nonatomic, assign) UIEdgeInsets padding;

//栅格内子视图的对齐停靠方式，只有叶子栅格设置才有意义。要想设置的gravity生效，叶子栅格内填充的子视图必须要设置明确的尺寸。
@property(nonatomic, assign) MyGravity gravity;

//占位标志，只用叶子栅格，当设置为YES时则表示这个格子只用于占位，子视图不能填充到这个栅格中。
@property(nonatomic, assign) BOOL placeholder;

/**顶部边界线*/
@property(nonatomic, strong) MyBorderline *topBorderline;
/**头部边界线*/
@property(nonatomic, strong) MyBorderline *leadingBorderline;
/**底部边界线*/
@property(nonatomic, strong) MyBorderline *bottomBorderline;
/**尾部边界线*/
@property(nonatomic, strong) MyBorderline *trailingBorderline;


/**
 *如果您不需要考虑国际化的问题则请用这个属性设置左边边界线，否则用leadingBorderline
 */
@property(nonatomic, strong) MyBorderline *leftBorderline;
/**
 *如果您不需要考虑国际化的问题则请用这个属性设置右边边界线，否则用trailingBorderline
 */
@property(nonatomic, strong) MyBorderline *rightBorderline;




//用字典的方式来构造格子。
@property(nonatomic, strong) NSDictionary *gridDictionary;


@end


