//
//  BookService.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSONModelLib.h"
#import "BookModel.h"
#import "AuthorModel.h"

@protocol BookServiceDidFetchDataDelegate <NSObject>

-(void) serviceDidFinishFetchingData:(id)json;

@end

@interface BookService : NSObject

@property(nonatomic,strong) NSArray *booksArray;
@property(nonatomic,strong) id<BookServiceDidFetchDataDelegate> delegate;

-(void)fetchDataWithURLString:(NSString *)stringURL;

@end
