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

#pragma mark - CoreDataManager interface

/**
 * This class implements the delegate method of BookManager class
 *
 */

@interface CoreDataManager : NSObject<BookManagerFetchDataDelegate>

/**
 * this method instantiates the BookManager class and sets itself as the delegate of that class
 * calls the fetchData method of that class
 *
 */
-(void)fetchData;

/**
 * this is the method which is called by the delegate method implemented of BookManager class. 
 * 
 * @param modelArray is the array which the delegate method passes of models which will be used to persist the information into the database by iterating over it
 *
 */
-(void)saveCoreDataWithModelArray:(NSArray *)modelArray;


@end
