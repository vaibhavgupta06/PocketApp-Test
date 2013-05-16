//
//  BookManager.h
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

//
// This is the manager class which performs all the business logic
// of loading the JSONModels
//

//
//This is the URL which will be sent to the service class
//
#define kPocketAppBookURLString @"http://dev.pocketapp.co.uk:8080/PocketAppTestData-0.1/book/listAsJson"

#import <Foundation/Foundation.h>
#import "BookService.h"
#import "BookModel.h"
#import "AuthorModel.h"

#pragma mark - BookManager protocol

/**
 * This is the protocol which CoreDataManager will confirm to.
 *
 */
@protocol BookManagerFetchDataDelegate <NSObject>

/**
 * this required protocol method tells the delegate that BookManager has finished loading the data into the JsonModels
 *
 * @param modelData is the array of BookModels which has to be sent to CoreDataManager for persisting in the database
 *
 */

-(void)managerDidFinishFetchingData:(NSArray *)modelData;

@end

#pragma mark - BookManager interface

/** 
 * Book Manager confirms to the BookServiceFetchDataDelegate 
 *
 */

@interface BookManager : NSObject <BookServiceFetchDataDelegate>

/**
 * this is the property which will be loaded with the JSONModels of type BookModel
 *
 */
@property(nonatomic,strong) NSArray *bookModelsArray;

/**
 * this is the delegate method which will be sent a message managerDidFinishFetchingData when the bookModelsArray will be loaded successfully
 *
 */

@property(nonatomic,strong) id<BookManagerFetchDataDelegate> delegate;

/**
 * This is the method which will be called by CoreDataManager's fetchData method 
 * this method instantiates the BookService class, sets its delegate to self and calls the fetchDataWithURLWithString method of that class
 */

-(void)fetchData;



@end
