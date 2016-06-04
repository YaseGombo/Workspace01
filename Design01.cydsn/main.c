/* ========================================
 *
 * Copyright YOUR COMPANY, THE YEAR
 * All Rights Reserved
 * UNPUBLISHED, LICENSED SOFTWARE.
 *
 * CONFIDENTIAL AND PROPRIETARY INFORMATION
 * WHICH IS THE PROPERTY OF your company.
 *
 * ========================================
*/
#include <project.h>
#include "globalVariables.h"
#include "stdio.h"

/********************************/
/* Grobal Varialbes             */
/********************************/
int16 const table_pphi[LENGTH_TABLE] = {
  // 2048,2037,2026,2014,2003,1991,1980,1968,1956,1945,1933,1921,1909,1897,1885,1873,1861,1849,1837,1824,1812,1800,1787,1775,1763,1750,1738,1725,1713,1700,1688,1675,1662,1650,1637,1624,1611,1598,1585,1573,1560,1547,1534,1520,1507,1494,1481,1467,1454,1441,1427,1413,1400,1386,1372,1358,1344,1330,1316,1302,1287,1273,1258,1244,1229,1214,1199,1184,1168,1153,1137,1122,1106,1090,1074,1057,1041,1025,1008,991,974,957,940,922,905,887,869,851,833,814,796,777,758,739,720,701,681,662,642,622,602,582,561,541,520,500,479,458,437,416,395,373,352,330,309,287,265,243,221,199,177,155,133,111,89,67,44,22,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,22,44,67,89,111,133,155,177,199,221,243,265,287,309,330,352,373,395,416,437,458,479,500,520,541,561,582,602,622,642,662,681,701,720,739,758,777,796,814,833,851,869,887,905,922,940,957,974,991,1008,1025,1041,1057,1074,1090,1106,1122,1137,1153,1168,1184,1199,1214,1229,1244,1258,1273,1287,1302,1316,1330,1344,1358,1372,1386,1400,1413,1427,1441,1454,1467,1481,1494,1507,1520,1534,1547,1560,1573,1585,1598,1611,1624,1637,1650,1662,1675,1688,1700,1713,1725,1738,1750,1763,1775,1787,1800,1812,1824,1837,1849,1861,1873,1885,1897,1909,1921,1933,1945,1956,1968,1980,1991,2003,2014,2026,2037,2048,2059,2070,2081,2092,2102,2113,2123,2134,2144,2154,2164,2174,2184,2193,2203,2212,2221,2230,2239,2248,2256,2265,2273,2281,2289,2297,2304,2312,2319,2326,2333,2340,2346,2352,2358,2364,2370,2376,2381,2387,2392,2397,2401,2406,2410,2415,2419,2423,2427,2430,2434,2437,2440,2443,2446,2449,2452,2455,2457,2459,2462,2464,2466,2468,2470,2472,2474,2476,2478,2480,2481,2483,2485,2487,2488,2490,2492,2494,2496,2497,2499,2501,2504,2506,2508,2510,2513,2515,2518,2521,2524,2527,2530,2534,2537,2541,2545,2549,2553,2558,2562,2567,2572,2577,2583,2589,2595,2601,2607,2614,2621,2628,2635,2643,2650,2659,2667,2675,2684,2693,2703,2712,2722,2732,2742,2753,2764,2775,2786,2797,2809,2821,2833,2845,2858,2871,2884,2897,2910,2924,2937,2951,2965,2979,2994,3008,3023,3038,3053,3068,3083,3098,3113,3128,3144,3159,3175,3191,3206,3222,3238,3254,3269,3285,3301,3317,3332,3348,3364,3379,3395,3410,3426,3441,3456,3471,3487,3502,3516,3531,3546,3560,3575,3589,3603,3617,3631,3644,3658,3671,3684,3697,3710,3722,3735,3747,3759,3771,3782,3793,3805,3816,3826,3837,3847,3857,3867,3877,3886,3895,3904,3913,3922,3930,3938,3946,3954,3961,3969,3976,3983,3989,3996,4002,4008,4013,4019,4024,4030,4034,4039,4044,4048,4052,4056,4060,4064,4067,4070,4073,4076,4078,4081,4083,4085,4087,4089,4090,4092,4093,4094,4095,4095,4096,4096,4096,4096,4096,4095,4095,4094,4093,4092,4090,4089,4087,4085,4083,4081,4078,4076,4073,4070,4067,4064,4060,4056,4052,4048,4044,4039,4034,4030,4024,4019,4013,4008,4002,3996,3989,3983,3976,3969,3961,3954,3946,3938,3930,3922,3913,3904,3895,3886,3877,3867,3857,3847,3837,3826,3816,3805,3793,3782,3771,3759,3747,3735,3722,3710,3697,3684,3671,3658,3644,3631,3617,3603,3589,3575,3560,3546,3531,3516,3502,3487,3471,3456,3441,3426,3410,3395,3379,3364,3348,3332,3317,3301,3285,3269,3254,3238,3222,3206,3191,3175,3159,3144,3128,3113,3098,3083,3068,3053,3038,3023,3008,2994,2979,2965,2951,2937,2924,2910,2897,2884,2871,2858,2845,2833,2821,2809,2797,2786,2775,2786,2797,2809,2821,2833,2845,2858,2871,2884,2897,2910,2924,2937,2951,2965,2979,2994,3008,3023,3038,3053,3068,3083,3098,3113,3128,3144,3159,3175,3191,3206,3222,3238,3254,3269,3285,3301,3317,3332,3348,3364,3379,3395,3410,3426,3441,3456,3471,3487,3502,3516,3531,3546,3560,3575,3589,3603,3617,3631,3644,3658,3671,3684,3697,3710,3722,3735,3747,3759,3771,3782,3793,3805,3816,3826,3837,3847,3857,3867,3877,3886,3895,3904,3913,3922,3930,3938,3946,3954,3961,3969,3976,3983,3989,3996,4002,4008,4013,4019,4024,4030,4034,4039,4044,4048,4052,4056,4060,4064,4067,4070,4073,4076,4078,4081,4083,4085,4087,4089,4090,4092,4093,4094,4095,4095,4096,4096,4096,4096,4096,4095,4095,4094,4093,4092,4090,4089,4087,4085,4083,4081,4078,4076,4073,4070,4067,4064,4060,4056,4052,4048,4044,4039,4034,4030,4024,4019,4013,4008,4002,3996,3989,3983,3976,3969,3961,3954,3946,3938,3930,3922,3913,3904,3895,3886,3877,3867,3857,3847,3837,3826,3816,3805,3793,3782,3771,3759,3747,3735,3722,3710,3697,3684,3671,3658,3644,3631,3617,3603,3589,3575,3560,3546,3531,3516,3502,3487,3471,3456,3441,3426,3410,3395,3379,3364,3348,3332,3317,3301,3285,3269,3254,3238,3222,3206,3191,3175,3159,3144,3128,3113,3098,3083,3068,3053,3038,3023,3008,2994,2979,2965,2951,2937,2924,2910,2897,2884,2871,2858,2845,2833,2821,2809,2797,2786,2775,2764,2753,2742,2732,2722,2712,2703,2693,2684,2675,2667,2659,2650,2643,2635,2628,2621,2614,2607,2601,2595,2589,2583,2577,2572,2567,2562,2558,2553,2549,2545,2541,2537,2534,2530,2527,2524,2521,2518,2515,2513,2510,2508,2506,2504,2501,2499,2497,2496,2494,2492,2490,2488,2487,2485,2483,2481,2480,2478,2476,2474,2472,2470,2468,2466,2464,2462,2459,2457,2455,2452,2449,2446,2443,2440,2437,2434,2430,2427,2423,2419,2415,2410,2406,2401,2397,2392,2387,2381,2376,2370,2364,2358,2352,2346,2340,2333,2326,2319,2312,2304,2297,2289,2281,2273,2265,2256,2248,2239,2230,2221,2212,2203,2193,2184,2174,2164,2154,2144,2134,2123,2113,2102,2092,2081,2070,2059
  2042,2031,2020,2009,1997,1986,1974,1962,1951,1939,1927,1915,1903,1891,1879,1867,1855,1843,1830,1818,1806,1794,1781,1769,1756,1744,1731,1719,1706,1694,1681,1669,1656,1643,1630,1618,1605,1592,1579,1566,1553,1540,1527,1514,1501,1487,1474,1461,1447,1434,1420,1407,1393,1379,1365,1351,1337,1323,1309,1295,1280,1266,1251,1236,1221,1206,1191,1176,1161,1145,1129,1114,1098,1082,1066,1049,1033,1016,999,983,965,948,931,913,896,878,860,842,823,805,786,767,749,729,710,691,671,652,632,612,592,572,551,531,510,489,468,447,426,405,384,362,341,319,298,276,254,232,210,188,166,144,122,100,78,56,33,11,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,11,33,56,78,100,122,144,166,188,210,232,254,276,298,319,341,362,384,405,426,447,468,489,510,531,551,572,592,612,632,652,671,691,710,729,749,767,786,805,823,842,860,878,896,913,931,948,965,983,999,1016,1033,1049,1066,1082,1098,1114,1129,1145,1161,1176,1191,1206,1221,1236,1251,1266,1280,1295,1309,1323,1337,1351,1365,1379,1393,1407,1420,1434,1447,1461,1474,1487,1501,1514,1527,1540,1553,1566,1579,1592,1605,1618,1630,1643,1656,1669,1681,1694,1706,1719,1731,1744,1756,1769,1781,1794,1806,1818,1830,1843,1855,1867,1879,1891,1903,1915,1927,1939,1951,1962,1974,1986,1997,2009,2020,2031,2042,2054,2065,2076,2086,2097,2108,2118,2129,2139,2149,2159,2169,2179,2189,2198,2208,2217,2226,2235,2244,2252,2261,2269,2277,2285,2293,2301,2308,2315,2322,2329,2336,2343,2349,2355,2362,2367,2373,2379,2384,2389,2394,2399,2404,2408,2413,2417,2421,2425,2428,2432,2435,2439,2442,2445,2448,2451,2453,2456,2458,2461,2463,2465,2467,2469,2471,2473,2475,2477,2479,2480,2482,2484,2486,2487,2489,2491,2493,2495,2497,2498,2500,2503,2505,2507,2509,2512,2514,2517,2520,2522,2525,2529,2532,2535,2539,2543,2547,2551,2555,2560,2565,2570,2575,2580,2586,2592,2598,2604,2610,2617,2624,2631,2639,2647,2654,2663,2671,2680,2689,2698,2707,2717,2727,2737,2748,2758,2769,2780,2792,2803,2815,2827,2839,2852,2864,2877,2890,2903,2917,2930,2944,2958,2972,2987,3001,3016,3030,3045,3060,3075,3090,3105,3121,3136,3152,3167,3183,3198,3214,3230,3246,3261,3277,3293,3309,3324,3340,3356,3371,3387,3403,3418,3433,3449,3464,3479,3494,3509,3524,3539,3553,3568,3582,3596,3610,3624,3638,3651,3664,3678,3691,3703,3716,3729,3741,3753,3765,3776,3788,3799,3810,3821,3832,3842,3852,3862,3872,3882,3891,3900,3909,3918,3926,3934,3942,3950,3958,3965,3972,3979,3986,3992,3999,4005,4011,4016,4022,4027,4032,4037,4042,4046,4050,4054,4058,4062,4065,4069,4072,4075,4077,4080,4082,4084,4086,4088,4090,4091,4092,4093,4094,4095,4095,4096,4096,4096,4096,4095,4095,4094,4093,4092,4091,4090,4088,4086,4084,4082,4080,4077,4075,4072,4069,4065,4062,4058,4054,4050,4046,4042,4037,4032,4027,4022,4016,4011,4005,3999,3992,3986,3979,3972,3965,3958,3950,3942,3934,3926,3918,3909,3900,3891,3882,3872,3862,3852,3842,3832,3821,3810,3799,3788,3776,3765,3753,3741,3729,3716,3703,3691,3678,3664,3651,3638,3624,3610,3596,3582,3568,3553,3539,3524,3509,3494,3479,3464,3449,3433,3418,3403,3387,3371,3356,3340,3324,3309,3293,3277,3261,3246,3230,3214,3198,3183,3167,3152,3136,3121,3105,3090,3075,3060,3045,3030,3016,3001,2987,2972,2958,2944,2930,2917,2903,2890,2877,2864,2852,2839,2827,2815,2803,2792,2780,2780,2792,2803,2815,2827,2839,2852,2864,2877,2890,2903,2917,2930,2944,2958,2972,2987,3001,3016,3030,3045,3060,3075,3090,3105,3121,3136,3152,3167,3183,3198,3214,3230,3246,3261,3277,3293,3309,3324,3340,3356,3371,3387,3403,3418,3433,3449,3464,3479,3494,3509,3524,3539,3553,3568,3582,3596,3610,3624,3638,3651,3664,3678,3691,3703,3716,3729,3741,3753,3765,3776,3788,3799,3810,3821,3832,3842,3852,3862,3872,3882,3891,3900,3909,3918,3926,3934,3942,3950,3958,3965,3972,3979,3986,3992,3999,4005,4011,4016,4022,4027,4032,4037,4042,4046,4050,4054,4058,4062,4065,4069,4072,4075,4077,4080,4082,4084,4086,4088,4090,4091,4092,4093,4094,4095,4095,4096,4096,4096,4096,4095,4095,4094,4093,4092,4091,4090,4088,4086,4084,4082,4080,4077,4075,4072,4069,4065,4062,4058,4054,4050,4046,4042,4037,4032,4027,4022,4016,4011,4005,3999,3992,3986,3979,3972,3965,3958,3950,3942,3934,3926,3918,3909,3900,3891,3882,3872,3862,3852,3842,3832,3821,3810,3799,3788,3776,3765,3753,3741,3729,3716,3703,3691,3678,3664,3651,3638,3624,3610,3596,3582,3568,3553,3539,3524,3509,3494,3479,3464,3449,3433,3418,3403,3387,3371,3356,3340,3324,3309,3293,3277,3261,3246,3230,3214,3198,3183,3167,3152,3136,3121,3105,3090,3075,3060,3045,3030,3016,3001,2987,2972,2958,2944,2930,2917,2903,2890,2877,2864,2852,2839,2827,2815,2803,2792,2780,2769,2758,2748,2737,2727,2717,2707,2698,2689,2680,2671,2663,2654,2647,2639,2631,2624,2617,2610,2604,2598,2592,2586,2580,2575,2570,2565,2560,2555,2551,2547,2543,2539,2535,2532,2529,2525,2522,2520,2517,2514,2512,2509,2507,2505,2503,2500,2498,2497,2495,2493,2491,2489,2487,2486,2484,2482,2480,2479,2477,2475,2473,2471,2469,2467,2465,2463,2461,2458,2456,2453,2451,2448,2445,2442,2439,2435,2432,2428,2425,2421,2417,2413,2408,2404,2399,2394,2389,2384,2379,2373,2367,2362,2355,2349,2343,2336,2329,2322,2315,2308,2301,2293,2285,2277,2269,2261,2252,2244,2235,2226,2217,2208,2198,2189,2179,2169,2159,2149,2139,2129,2118,2108,2097,2086,2076,2065,2054
};  // Max value: 4096
int16 const table_pLpphi[LENGTH_TABLE] = {
  // 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,7,40,74,108,141,175,210,244,278,313,348,382,417,452,487,522,557,591,626,661,696,731,765,800,835,869,904,938,972,1006,1041,1075,1109,1143,1176,1210,1244,1277,1311,1344,1378,1411,1444,1477,1511,1544,1577,1610,1643,1676,1709,1741,1774,1807,1840,1873,1906,1938,1971,2004,2037,2070,2102,2135,2168,2201,2234,2267,2300,2333,2366,2399,2431,2464,2497,2530,2563,2596,2629,2662,2695,2728,2760,2793,2826,2858,2890,2923,2955,2987,3019,3051,3082,3114,3145,3176,3207,3238,3268,3298,3328,3357,3386,3415,3443,3471,3499,3526,3553,3580,3605,3631,3656,3680,3704,3727,3750,3772,3794,3815,3835,3855,3874,3892,3909,3926,3942,3958,3972,3986,3999,4012,4023,4034,4044,4053,4061,4068,4075,4080,4085,4089,4092,4094,4096,4096,4096,4094,4092,4089,4085,4080,4075,4068,4061,4053,4044,4034,4023,4012,3999,3986,3972,3958,3942,3926,3909,3892,3874,3855,3835,3815,3794,3772,3750,3727,3704,3680,3656,3631,3605,3580,3553,3526,3499,3471,3443,3415,3386,3357,3328,3298,3268,3238,3207,3176,3145,3114,3082,3051,3019,2987,2955,2923,2890,2858,2826,2793,2760,2728,2695,2662,2629,2596,2563,2530,2497,2464,2431,2399,2366,2333,2300,2267,2234,2201,2168,2135,2102,2070,2037,2004,1971,1938,1906,1873,1840,1807,1774,1741,1709,1676,1643,1610,1577,1544,1511,1477,1444,1411,1378,1344,1311,1277,1244,1210,1176,1143,1109,1075,1041,1006,972,938,904,869,835,800,765,731,696,661,626,591,557,522,487,452,417,382,348,313,278,244,210,175,141,108,74,40,7,-26,-59,-91,-123,-155,-186,-217,-248,-278,-307,-336,-365,-393,-420,-447,-473,-498,-523,-547,-570,-593,-614,-635,-655,-674,-692,-709,-725,-740,-754,-767,-779,-790,-799,-808,-815,-821,-826,-830,-832,-833,-832,-831,-828,-823,-818,-811,-802,-792,-781,-768,-754,-739,-722,-703,-683,-662,-639,-615,-589,-562,-534,-504,-473,-441,-407,-371,-335,-297,-258,-217,-176,-133,-89,-43,3,51,99,149,200,251,304,357,412,467,523,580,637,695,754,813,873,933,994,1055,1117,1179,1241,1303,1365,1428,1490,1553,1616,1678,1740,1802,1864,1926,1987,2048,2108,2168,2228,2287,2345,2402,2459,2515,2570,2625,2678,2731,2782,2833,2883,2931,2978,3024,3069,3113,3156,3197,3237,3275,3312,3348,3382,3415,3446,3476,3504,3531,3557,3580,3602,3623,3642,3659,3675,3689,3701,3712,3721,3728,3734,3738,3741,3742,3741,3739,3735,3729,3722,3713,3702,3690,3677,3661,3645,3626,3607,3585,3562,3538,3513,3485,3457,3427,3396,3363,3329,3294,3257,3220,3181,3141,3099,3057,3013,2968,2922,2876,2828,2779,2729,2678,2626,2573,2520,2466,2410,2354,2297,2240,2182,2123,2063,2002,1942,1880,1818,1755,1692,1628,1564,1499,1434,1368,1302,1236,1176,1143,1109,1075,1041,1006,972,938,904,869,835,800,765,731,696,661,626,591,557,522,487,452,417,382,348,313,278,244,210,175,141,108,74,40,7,-26,-59,-91,-123,-155,-186,-217,-248,-278,-307,-336,-365,-393,-420,-447,-473,-498,-523,-547,-570,-593,-614,-635,-655,-674,-692,-709,-725,-740,-754,-767,-779,-790,-799,-808,-815,-821,-826,-830,-832,-833,-832,-831,-828,-823,-818,-811,-802,-792,-781,-768,-754,-739,-722,-703,-683,-662,-639,-615,-589,-562,-534,-504,-473,-441,-407,-371,-335,-297,-258,-217,-176,-133,-89,-43,3,51,99,149,200,251,304,357,412,467,523,580,637,695,754,813,873,933,994,1055,1117,1179,1241,1303,1365,1428,1490,1553,1616,1678,1740,1802,1864,1926,1987,2048,2108,2168,2228,2287,2345,2402,2459,2515,2570,2625,2678,2731,2782,2833,2883,2931,2978,3024,3069,3113,3156,3197,3237,3275,3312,3348,3382,3415,3446,3476,3504,3531,3557,3580,3602,3623,3642,3659,3675,3689,3701,3712,3721,3728,3734,3738,3741,3742,3741,3739,3735,3729,3722,3713,3702,3690,3677,3661,3645,3626,3607,3585,3562,3538,3513,3485,3457,3427,3396,3363,3329,3294,3257,3220,3181,3141,3099,3057,3013,2968,2922,2876,2828,2779,2729,2678,2626,2573,2520,2466,2410,2354,2297,2240,2182,2123,2063,2002,1942,1880,1818,1755,1692,1628,1564,1499,1434,1368,1302,1236,1169,1102,1035,967,899,831,763,694,625,556,487,418,348,279,209,139,70,-0,-70,-139,-209,-279,-348,-418,-487,-556,-625,-694,-763,-831,-899,-967,-1035,-1102,-1169,-1236,-1302,-1368,-1434,-1499,-1564,-1628,-1692,-1755,-1818,-1880,-1942,-2002,-2063,-2123,-2182,-2240,-2297,-2354,-2410,-2466,-2520,-2573,-2626,-2678,-2729,-2779,-2828,-2876,-2922,-2968,-3013,-3057,-3099,-3141,-3181,-3220,-3257,-3294,-3329,-3363,-3396,-3427,-3457,-3485,-3513,-3538,-3562,-3585,-3607,-3626,-3645,-3661,-3677,-3690,-3702,-3713,-3722,-3729,-3735,-3739,-3741,-3742,-3741,-3738,-3734,-3728,-3721,-3712,-3701,-3689,-3675,-3659,-3642,-3623,-3602,-3580,-3557,-3531,-3504,-3476,-3446,-3415,-3382,-3348,-3312,-3275,-3237,-3197,-3156,-3113,-3069,-3024,-2978,-2931,-2883,-2833,-2782,-2731,-2678,-2625,-2570,-2515,-2459,-2402,-2345,-2287,-2228,-2168,-2108,-2048,-1987,-1926,-1864,-1802,-1740,-1678,-1616,-1553,-1490,-1428,-1365,-1303,-1241,-1179,-1117,-1055,-994,-933,-873,-813,-754,-695,-637,-580,-523,-467,-412,-357,-304,-251,-200,-149,-99,-51,-3,43,89,133,176,217,258,297,335,371,407,441,473,504,534,562,589,615,639,662,683,703,722,739,754,768,781,792,802,811,818,823,828,831,832,833,832,830,826,821,815,808,799,790,779,767,754,740,725,709,692,674,655,635,614,593,570,547,523,498,473,447,420,393,365,336,307,278,248,217,186,155,123,91,59,26,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
  0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,24,57,91,124,158,193,227,261,296,330,365,400,435,469,504,539,574,609,644,679,713,748,783,817,852,886,921,955,989,1024,1058,1092,1126,1160,1193,1227,1261,1294,1328,1361,1394,1428,1461,1494,1527,1560,1593,1626,1659,1692,1725,1758,1791,1824,1856,1889,1922,1955,1988,2020,2053,2086,2119,2152,2185,2218,2250,2283,2316,2349,2382,2415,2448,2481,2514,2547,2580,2613,2646,2678,2711,2744,2777,2809,2842,2874,2907,2939,2971,3003,3035,3067,3098,3130,3161,3192,3222,3253,3283,3313,3343,3372,3401,3429,3458,3485,3513,3540,3567,3593,3618,3643,3668,3692,3716,3739,3761,3783,3804,3825,3845,3864,3883,3901,3918,3934,3950,3965,3979,3993,4006,4018,4029,4039,4048,4057,4065,4072,4078,4083,4087,4091,4093,4095,4096,4096,4095,4093,4091,4087,4083,4078,4072,4065,4057,4048,4039,4029,4018,4006,3993,3979,3965,3950,3934,3918,3901,3883,3864,3845,3825,3804,3783,3761,3739,3716,3692,3668,3643,3618,3593,3567,3540,3513,3485,3458,3429,3401,3372,3343,3313,3283,3253,3222,3192,3161,3130,3098,3067,3035,3003,2971,2939,2907,2874,2842,2809,2777,2744,2711,2678,2646,2613,2580,2547,2514,2481,2448,2415,2382,2349,2316,2283,2250,2218,2185,2152,2119,2086,2053,2020,1988,1955,1922,1889,1856,1824,1791,1758,1725,1692,1659,1626,1593,1560,1527,1494,1461,1428,1394,1361,1328,1294,1261,1227,1193,1160,1126,1092,1058,1024,989,955,921,886,852,817,783,748,713,679,644,609,574,539,504,469,435,400,365,330,296,261,227,193,158,124,91,57,24,-9,-42,-75,-107,-139,-170,-202,-232,-263,-292,-322,-351,-379,-407,-434,-460,-486,-511,-535,-559,-582,-604,-625,-645,-665,-683,-701,-717,-733,-747,-761,-773,-785,-795,-804,-812,-818,-824,-828,-831,-833,-833,-832,-830,-826,-821,-814,-807,-797,-787,-775,-761,-747,-730,-713,-693,-673,-651,-627,-602,-576,-548,-519,-489,-457,-424,-389,-353,-316,-277,-238,-197,-154,-111,-66,-20,27,75,124,174,225,277,330,384,439,495,551,608,666,724,783,843,903,964,1025,1086,1148,1210,1272,1334,1397,1459,1522,1584,1647,1709,1771,1833,1895,1957,2018,2078,2139,2198,2257,2316,2374,2431,2487,2543,2598,2652,2705,2757,2808,2858,2907,2955,3002,3047,3091,3135,3176,3217,3256,3294,3330,3365,3399,3431,3461,3491,3518,3544,3569,3592,3613,3633,3651,3667,3682,3695,3707,3717,3725,3732,3737,3740,3742,3742,3740,3737,3732,3726,3717,3708,3697,3684,3669,3653,3636,3617,3596,3574,3551,3526,3499,3471,3442,3412,3380,3346,3312,3276,3239,3200,3161,3120,3078,3035,2991,2946,2899,2852,2803,2754,2704,2652,2600,2547,2493,2438,2382,2326,2269,2211,2152,2093,2033,1972,1911,1849,1787,1724,1660,1596,1532,1467,1401,1335,1269,1203,1160,1126,1092,1058,1024,989,955,921,886,852,817,783,748,713,679,644,609,574,539,504,469,435,400,365,330,296,261,227,193,158,124,91,57,24,-9,-42,-75,-107,-139,-170,-202,-232,-263,-292,-322,-351,-379,-407,-434,-460,-486,-511,-535,-559,-582,-604,-625,-645,-665,-683,-701,-717,-733,-747,-761,-773,-785,-795,-804,-812,-818,-824,-828,-831,-833,-833,-832,-830,-826,-821,-814,-807,-797,-787,-775,-761,-747,-730,-713,-693,-673,-651,-627,-602,-576,-548,-519,-489,-457,-424,-389,-353,-316,-277,-238,-197,-154,-111,-66,-20,27,75,124,174,225,277,330,384,439,495,551,608,666,724,783,843,903,964,1025,1086,1148,1210,1272,1334,1397,1459,1522,1584,1647,1709,1771,1833,1895,1957,2018,2078,2139,2198,2257,2316,2374,2431,2487,2543,2598,2652,2705,2757,2808,2858,2907,2955,3002,3047,3091,3135,3176,3217,3256,3294,3330,3365,3399,3431,3461,3491,3518,3544,3569,3592,3613,3633,3651,3667,3682,3695,3707,3717,3725,3732,3737,3740,3742,3742,3740,3737,3732,3726,3717,3708,3697,3684,3669,3653,3636,3617,3596,3574,3551,3526,3499,3471,3442,3412,3380,3346,3312,3276,3239,3200,3161,3120,3078,3035,2991,2946,2899,2852,2803,2754,2704,2652,2600,2547,2493,2438,2382,2326,2269,2211,2152,2093,2033,1972,1911,1849,1787,1724,1660,1596,1532,1467,1401,1335,1269,1203,1136,1069,1001,933,865,797,728,660,591,522,452,383,313,244,174,105,35,-35,-105,-174,-244,-313,-383,-452,-522,-591,-660,-728,-797,-865,-933,-1001,-1069,-1136,-1203,-1269,-1335,-1401,-1467,-1532,-1596,-1660,-1724,-1787,-1849,-1911,-1972,-2033,-2093,-2152,-2211,-2269,-2326,-2382,-2438,-2493,-2547,-2600,-2652,-2704,-2754,-2803,-2852,-2899,-2946,-2991,-3035,-3078,-3120,-3161,-3200,-3239,-3276,-3312,-3346,-3380,-3412,-3442,-3471,-3499,-3526,-3551,-3574,-3596,-3617,-3636,-3653,-3669,-3684,-3697,-3708,-3717,-3726,-3732,-3737,-3740,-3742,-3742,-3740,-3737,-3732,-3725,-3717,-3707,-3695,-3682,-3667,-3651,-3633,-3613,-3592,-3569,-3544,-3518,-3491,-3461,-3431,-3399,-3365,-3330,-3294,-3256,-3217,-3176,-3135,-3091,-3047,-3002,-2955,-2907,-2858,-2808,-2757,-2705,-2652,-2598,-2543,-2487,-2431,-2374,-2316,-2257,-2198,-2139,-2078,-2018,-1957,-1895,-1833,-1771,-1709,-1647,-1584,-1522,-1459,-1397,-1334,-1272,-1210,-1148,-1086,-1025,-964,-903,-843,-783,-724,-666,-608,-551,-495,-439,-384,-330,-277,-225,-174,-124,-75,-27,20,66,111,154,197,238,277,316,353,389,424,457,489,519,548,576,602,627,651,673,693,713,730,747,761,775,787,797,807,814,821,826,830,832,833,833,831,828,824,818,812,804,795,785,773,761,747,733,717,701,683,665,645,625,604,582,559,535,511,486,460,434,407,379,351,322,292,263,232,202,170,139,107,75,42,9,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
};  // Max value: 4096
const int8 table_phase[8] = {
  6, // Hall State: 0b000 -> Error (Short)
  3, // Hall State: 0b001 -> Phase 3
  1, // Hall State: 0b010 -> Phase 1
  2, // Hall State: 0b011 -> Phase 2
  5, // Hall State: 0b100 -> Phase 5
  4, // Hall State: 0b101 -> Phase 4
  0, // Hall State: 0b110 -> Phase 0
  7  // Hall State: 0b111 -> Error (Open)
};
const uint8 table_hallState[8] = {  // bit2:sensorA(green), bit1:sensorB(white), bit0:sensorC(orange). 0b00000(A)(B)(C).
  HALL_STATE_0,  // Phase 0
  HALL_STATE_1,  // Phase 1
  HALL_STATE_2,  // Phase 2
  HALL_STATE_3,  // Phase 3
  HALL_STATE_4,  // Phase 4
  HALL_STATE_5,  // Phase 5
  HALL_STATE_SHORT,  // Error (Short)
  HALL_STATE_OPEN   // Error (Open)
};

uint16 status_error;

HallHist hallHist;
AngleParams angleParams;

void Set_angleParams_Center(){
  angleParams.thm0 = ((hallHist.phase[0] << 1) + 1) * (THETA_60DEG >> 1);
  angleParams.wm0 = 0L;
  angleParams.am0 = 0L;
  angleParams.direction = DIR_VERYSLOW;
  angleParams.updated = 1;
}

void Set_angleParams_Forward(){
  angleParams.thm0 = hallHist.phase[0] * THETA_60DEG
                     + THETA_OFFSET;
  angleParams.thm0 %= THETA_360DEG;
  int32 w_1 = (THETA_60DEG << 1) / (hallHist.time[0] + hallHist.time[1]);
  int32 dw = (THETA_60DEG / hallHist.time[0]) - (THETA_60DEG / hallHist.time[1]);
  angleParams.wm0 = w_1 + dw;
  angleParams.am0 = (w_1 * dw) / (THETA_60DEG >> BITs_BIAS_ACC);
  angleParams.direction = DIR_NORMAL;
  angleParams.updated = 1;
}

void Set_angleParams_Backward(){
  angleParams.thm0 = (hallHist.phase[0] + 1) * THETA_60DEG - 1
                     + THETA_OFFSET - THETA_HIS;
  angleParams.thm0 %= THETA_360DEG;
  int32 w_1 = - ((THETA_60DEG << 1) / (hallHist.time[0] + hallHist.time[1]));
  int32 dw = - ((THETA_60DEG / hallHist.time[0]) - (THETA_60DEG / hallHist.time[1]));
  angleParams.wm0 = w_1 + dw;
  angleParams.am0 = ((-w_1) * dw) / (THETA_60DEG >> BITs_BIAS_ACC);
  angleParams.direction = DIR_INVERSE;
  angleParams.updated = 1;
}

#ifdef DEBUG
volatile uint32 SysCntVal;
#endif

/*****************************************************************************\
 * Function:    MyInit
 * Input:       void
 * Returns:     void
 * Description: 
 *     Initiallization
\*****************************************************************************/
void MyInit()
{
  status_error = NO_ERROR;  // = 0;
  
  uint8 initial_hallState = Status_Reg_Hall_Read();
  uint16 initial_time = Counter_Hall_ReadPeriod();
  int i;
  for(i = 0; i < LENGTH_HIST; i++){
    hallHist.phase[i] = table_phase[initial_hallState];
    hallHist.time[i] = initial_time;
  }
  
  Set_angleParams_Center();
}

/********************************/
/* main function                */
/********************************/
int main()
{
    CyGlobalIntEnable; /* Enable global interrupts. */

    /* Place your initialization/startup code here (e.g. MyInst_Start()) */
    MyInit();
    
    UART_1_Start();
    ISR_Hall_Start();
    ISR_PWM_TC_Start();
    
    Control_Reg_PWM_Reset_Write(1);
    PWM_A_Start();
    PWM_B_Start();
    PWM_C_Start();
    Control_Reg_PWM_Reset_Write(0);
    
    for(;;)
    {
        /* Place your application code here. */
        // Chtemp = UART_1_GetChar();
        // if(Chtemp != 0){     
        //   Ch = Chtemp;
        //     sprintf(TransmitBuffer, "Received value: %x\r\n", Ch);
        //     UART_1_PutString(TransmitBuffer);
        // } else {
          // Ch = (Ch == 0xFE) ? 0x00 : Ch + 0x01;
        // }
        
        // countValue[0] = Timer_1_ReadCounter();
        // PWM_A_WriteCompare(Ch);
        // PWM_B_WriteCompare(Ch);
        // PWM_C_WriteCompare(Ch);
        // countValue[1] = Timer_1_ReadCounter();  // About 56-14 = 42 = 14*3 cycles
        /*
        if(i < 16){
          i++;
          sprintf(TransmitBuffer, "%d ", countValue[0] - countValue[1]);
          UART_1_PutString(TransmitBuffer);
        }
        */
    }
}
/* [] END OF FILE */