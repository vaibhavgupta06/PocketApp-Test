//
//  CoreDataManager.m
//  PocketAppTest
//
//  Created by Vaibhav Gupta on 16/05/13.
//  Copyright (c) 2013 Vaibhav Gupta. All rights reserved.
//

#import "CoreDataManager.h"

@implementation CoreDataManager

-(void)fetchData
{
    BookManager *manager = [[BookManager alloc] init];
    manager.delegate = self;
    [manager fetchData];
}


-(void)managerDidFinishFetchingData:(NSArray *)modelData
{
    [self saveCoreDataWithModelArray:modelData];
    
}

-(void)saveCoreDataWithModelArray:(NSArray *)modelArray
{
    //Create a reference to the App Delegate
    AppDelegate *appDelegate = [[UIApplication sharedApplication] delegate];
    
    //Create a reference to Managed Object Context
    NSManagedObjectContext *context = appDelegate.managedObjectContext;
    
    NSEntityDescription *description = [NSEntityDescription entityForName:@"Book" inManagedObjectContext:context];
    
    NSError *error;
    NSFetchRequest *fetchRequest = [[NSFetchRequest alloc] init];
    [fetchRequest setEntity:description];
    NSArray *books = [context executeFetchRequest:fetchRequest error:&error];
    if (error) {
        NSLog(@"Unable to fetch with error : %@ %@",error,[error userInfo]);
    }
    
    //Check if the number of books in the database is equal to the number of books in web service
    if (books.count!=modelArray.count) {
        
        //This Means the database does not have all the objects which are present in web service
        //Thus the database has to be updated with fresh data
        for (Book *book in books) {
            [context deleteObject:book];
        }
        if (![context save:&error]) {
            NSLog(@"Unable to delete Objects already present : %@ %@",error,[error userInfo]);
        }
        
        // Iterate over the modelArray using Fast enumeration to persist the Objects in Core Data
        for (BookModel *bookModel in modelArray) {
            Book *book = [NSEntityDescription insertNewObjectForEntityForName:@"Book" inManagedObjectContext:context];
            book.title = bookModel.title;
            book.bookId = bookModel.bookId;
            book.lastUpdated = bookModel.lastUpdated;
            book.dateCreated = bookModel.dateCreated;
            
            Author *author = [NSEntityDescription insertNewObjectForEntityForName:@"Author" inManagedObjectContext:context];
            author.firstName = bookModel.author.firstName;
            author.lastName = bookModel.author.lastName;
            author.dateCreated = bookModel.author.dateCreated;
            author.lastUpdated = bookModel.author.lastUpdated;
            author.authorId = bookModel.author.authorId;
            
            book.author = author;
            
            NSError *error;
            if (![context save:&error]) {
                NSLog(@"Error ocurred : %@ %@", error,[error userInfo]);
            }
            else {
                NSLog(@"Saved Successfully");
            }
        }
    }
    
    //Check if the number of books in database is equal to the number of books in web service
    if (books.count==modelArray.count) {
        //This means the database is up to date with the latest data in web service
        NSLog(@"Number of books in database are up to date with the web service");
    }
    
    
            
    
            
    
    
    
}

@end
