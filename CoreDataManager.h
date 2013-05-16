//
//  CoreDataManager.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "BookManager.h"
#import "AppDelegate.h"
#import "BookModel.h"
#import "AuthorModel.h"
#import "Book.h"
#import "Author.h"

@interface CoreDataManager : NSObject<BookManagerFetchDataDelegate>

-(void)fetchData;
-(void)saveCoreDataWithModelArray:(NSArray *)modelArray;


@end
