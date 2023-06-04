#include <stdio.h>
#include <thread>

#include "CycleTimer.h"

typedef struct {
    float x0, x1;
    float y0, y1;
    unsigned int width;
    unsigned int height;
    int maxIterations;
    int* output;
    int threadId;
    int numThreads;
} WorkerArgs;


extern void mandelbrotSerial(
    float x0, float y0, float x1, float y1,
    int width, int height,
    int startRow, int numRows,
    int maxIterations,
    int output[]);

int thread_num;
//
// workerThreadStart --
//
// Thread entrypoint.
void workerThreadStart(WorkerArgs * const args) {


    // TODO FOR CS149 STUDENTS: Implement the body of the worker
    // thread here. Each thread should make a call to mandelbrotSerial()
    // to compute a part of the output image.  For example, in a
    // program that uses two threads, thread 0 could compute the top
    // half of the image and thread 1 could compute the bottom half.

    // 1
    // std::thread thread1(mandelbrotSerial, args->x0, args->y0, args->x1, args->y1, args->width, 
    // args->height, 0, args->height/2, args->maxIterations, args->output); 
    // thread1.join();
    // std::thread thread0(mandelbrotSerial, args->x0, args->y0, args->x1, args->y1, args->width, 
    // args->height,args->height/2,args->height - args->height/2, args->maxIterations, args->output);
    // thread0.join();
    double startTime = CycleTimer::currentSeconds();
    mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
    args->width,args->height,
    args->threadId * args->height / thread_num, 
    args->threadId == thread_num - 1 ? args-> height - (args->height / thread_num * (thread_num - 1)) : args->height / thread_num,
    args->maxIterations,
    args->output);


    //16线程
//     int xx1 = args->height * 1.125  /   thread_num;
//     int xx2 =args->height * 0.375 /   thread_num;
//     int xx3 = args->height * 0.25 /   thread_num;
//     switch (args->threadId)
//     {
//         case 0:
//     mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     0,
//     xx1 ,
//     args->maxIterations,
//     args->output);
//         break;
//     case 1:
//         mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1,
//     xx1,
//     args->maxIterations,
//     args->output);
//     break;
//         case 2:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2,
//     xx2,
//     args->maxIterations,
//     args->output);
//         break;
// case 3:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2,
//     xx2,
//     args->maxIterations,
//     args->output);
// break;
// case 4:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 5:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 6:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 2,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 7:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 3,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 8:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 4,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 9:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 5,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 10:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 6,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 11:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 7,
//     xx3,
//     args->maxIterations,
//     args->output);
// break;
// case 12:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 2 + xx3 * 8,
//     xx2,
//     args->maxIterations,
//     args->output);
// break;

// case 13:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 3 + xx3 * 8,
//     xx2,
//     args->maxIterations,
//     args->output);
// break;
// case 14:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 2 + xx2 * 4 + xx3 * 8,
//     xx1,
//     args->maxIterations,
//     args->output);
// break;
// case 15:
//          mandelbrotSerial(args->x0,args->y0,args->x1,args->y1,
//     args->width,args->height,
//     xx1 * 3 + xx2 * 4 + xx3 * 8,
//     args->height - (xx1 * 3 + xx2 * 4 + xx3 * 8),
//     args->maxIterations,
//     args->output);
// break;

//     }
    
    double endTime = CycleTimer::currentSeconds();
    double totalTime=endTime-startTime;
    printf("word thread: %d time :%lf\n", thread_num, totalTime);
    // 2


    
    printf("Hello world from thread %d\n", args->threadId);
}

//
// MandelbrotThread --
//
// Multi-threaded implementation of mandelbrot set image generation.
// Threads of execution are created by spawning std::threads.
void mandelbrotThread(
    int numThreads,
    float x0, float y0, float x1, float y1,
    int width, int height,
    int maxIterations, int output[])
{
    static constexpr int MAX_THREADS = 32;
    thread_num = numThreads;
    if (numThreads > MAX_THREADS)
    {
        fprintf(stderr, "Error: Max allowed threads is %d\n", MAX_THREADS);
        exit(1);
    }

    // Creates thread objects that do not yet represent a thread.
    std::thread workers[MAX_THREADS];
    WorkerArgs args[MAX_THREADS];

    for (int i=0; i<numThreads; i++) {
      
        // TODO FOR CS149 STUDENTS: You may or may not wish to modify
        // the per-thread arguments here.  The code below copies the
        // same arguments for each thread
        args[i].x0 = x0;
        args[i].y0 = y0;
        args[i].x1 = x1;
        args[i].y1 = y1;
        args[i].width = width;
        args[i].height = height;
        args[i].maxIterations = maxIterations;
        args[i].numThreads = numThreads;
        args[i].output = output;
      
        args[i].threadId = i;
    }

    // Spawn the worker threads.  Note that only numThreads-1 std::threads
    // are created and the main application thread is used as a worker
    // as well.
    for (int i=1; i<numThreads; i++) {
        workers[i] = std::thread(workerThreadStart, &args[i]);
    }
    
    workerThreadStart(&args[0]);

    // join worker threads
    for (int i=1; i<numThreads; i++) {
        workers[i].join();
    }
}

