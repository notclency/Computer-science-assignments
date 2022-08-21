#include "m_add.h"
#include <gtest/gtest.h>



//this is a helper function that compares 2 arrays and returns a bool
//whether it matches or not
bool compare(MEDUSOID_NUMBER result, MEDUSOID_NUMBER expected_result);

bool compare(MEDUSOID_NUMBER result, MEDUSOID_NUMBER expected_result){

  
  bool value = true;
  int i = 0;
  
  while((i < MAX_SIZE) && (value)){
    if(result[i] == expected_result[i]){
      i ++;
    }else{
      value = false;
    }
  }

  return value;
}


//#1
//Both nums1 and num2 are all negative with 1 carry of -1 which is a
//stand alone carry
TEST(test_m_add, TEST_1){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-1,-2,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-2,-1,-1,-1,-2,-2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {2,-3,-3,-2,-3,-3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}


//#2
//Both nums1 and num2 are all negative and zeroes with 1 carry of -1 which is a
//stand alone carry
TEST(test_m_add, TEST_2){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-1,-2,-1,-1,0};
  MEDUSOID_NUMBER num2 = {-2,-1,-1,0,-2,-2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {2,-3,-3,-1,-3,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}


//#3
//Both nums1 and num2 have negative and positive digits
//with 1 carry of -1 which is a stand alone carry
TEST(test_m_add, TEST_3){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {1,-2,-2,2,3,-2};
  MEDUSOID_NUMBER num2 = {2,-3,3,-1,-3,2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,2,0,1,0,0};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}



//#4
//Both nums1 and num2 have negative and positive digits and zeroes
//with 1 carry of -1 which is a stand alone carry
TEST(test_m_add, TEST_4){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {1,-2,-2,2,3,0};
  MEDUSOID_NUMBER num2 = {2,-3,3,-1,0,2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,2,0,1,3,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#5
//Both nums1 and num2 are positive digits
//with 1 carry of 1 which is a stand alone carry
TEST(test_m_add, TEST_5){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {1,2,3,1,1,1};
  MEDUSOID_NUMBER num2 = {1,1,2,1,2,2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {2,3,-2,3,3,3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#6
//Both nums1 and num2 have positive digits, with zeroes
//with 1 carry of 1 which is a stand alone carry
TEST(test_m_add, TEST_6){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {1,2,3,1,0,1};
  MEDUSOID_NUMBER num2 = {1,1,2,0,3,2};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {2,3,-2,2,3,3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#7
//Both nums1 and num2 have a mix of positive ,negative digits and zeroes
//with 1 carry of 1 which is a stand alone carry
TEST(test_m_add, TEST_7){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-2,1,-3,-3,-2,0};
  MEDUSOID_NUMBER num2 = {3,3,3,2,3,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {1,-3,1,-1,1,1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
 
}


//#8
//Both nums1 and num2 have only negative digits
//with 2 or more carries of -1 which is a stand alone carry
TEST(test_m_add, TEST_8){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-1,-3,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-1,-1,-1,-1,-1,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,-3,3,-3,-2,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#9
//Both nums1 and num2 have only negative digits and zeroes
//with 2 or more carries of -1 which is a stand alone carry
TEST(test_m_add, TEST_9){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-1,-3,-1,-1,0};
  MEDUSOID_NUMBER num2 = {-1,-1,-1,-1,0,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,-3,3,-3,-1,-1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#10
//Both nums1 and num2 have negative, positive digits and zeroes
//with 2 or more carries of -1 which is a stand alone carry
TEST(test_m_add, TEST_10){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-1,-3,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-1,-1,-1,-1,-1,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,-3,3,-3,-2,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#11
//Both nums1 and num2 have negative, positive digits and zeroes
//with 2 or more carries of -1 which is a stand alone carry
TEST(test_m_add, TEST_11){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,2,-3,2,1,-1};
  MEDUSOID_NUMBER num2 = {-1,1,-1,1,-1,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {3,2,3,2,0,-1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
 
}


/******************************************************************/


//#12
//Both nums1 and num2 have a mix of negative and positive digits
//with 2 or more carries of -1 & 1 which is a stand alone carry
TEST(test_m_add, TEST_12){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,-1,1,-1,-2,1};
  MEDUSOID_NUMBER num2 = {3,1,3,1,1,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,1,-3,1,-1,0};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#13
//Both nums1 and num2 have negative, positive digits and zeroes
//with 2 or more carries of -1 & 1  which is a stand alone carry
TEST(test_m_add, TEST_13){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,0,1,1,0,1};
  MEDUSOID_NUMBER num2 = {3,2,3,1,0,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,3,-3,3,0,1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#14
//Both nums1 and num2 have negative and positive digits
//with 2 or more carries of 1 which is a stand alone carry
TEST(test_m_add, TEST_14){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,1,3,1,2,1};
  MEDUSOID_NUMBER num2 = {3,1,3,1,1,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,3,-1,3,3,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#15
//Both nums1 and num2 have negative ,positive digits and zeroes
//with 2 or more carries of 1 which is a stand alone carry
TEST(test_m_add, TEST_15){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,1,3,0,2,-1};
  MEDUSOID_NUMBER num2 = {3,1,3,1,0,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,3,-1,2,2,0};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}


//#16
//Both nums1 and num2 have negative and positive digits
//with 2 or more carries of 1 which is a stand alone carry
TEST(test_m_add, TEST_16){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,-1,3,-1,-1,-2};
  MEDUSOID_NUMBER num2 = {3,2,3,2,-2,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,2,-1,2,-3,-3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#17
//Both nums1 and num2 have negative and positive digits and zeroes
//with 2 or more carries of 1 which is a stand alone carry
TEST(test_m_add, TEST_17){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,-1,3,-1,-1,0};
  MEDUSOID_NUMBER num2 = {3,2,3,2,0,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false; 
  
  MEDUSOID_NUMBER expected_result = {-1,2,-1,2,-1,-1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}

//#18
//Both nums1 and num2 have negative digits
//with 2 or more carries of -1 which is a ripple  carry
TEST(test_m_add, TEST_18){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-3,-2,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-2,-3,-3,-1,-2,-2};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,0,1,-3,-3,-3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#19
//Both nums1 and num2 have negative digits and zeroes
//with 2 or more carries of -1 which is a ripple  carry
TEST(test_m_add, TEST_19){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-3,-2,-1,0,-1};
  MEDUSOID_NUMBER num2 = {-2,-3,-3,-1,-2,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,0,1,-3,-2,-1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}



//#20
//Both nums1 and num2 have negative , positive digits
//with 2 or more carries of -1 which is a ripple  carry
TEST(test_m_add, TEST_20){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-3,-2,-1,2,2};
  MEDUSOID_NUMBER num2 = {-2,-3,-3,-1,1,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,0,1,-3,3,3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#21
//Both nums1 and num2 have negative, positive digits and zeroes
//with 2 or more carries of -1 which is a ripple  carry
TEST(test_m_add, TEST_21){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,-3,-2,-1,0,2};
  MEDUSOID_NUMBER num2 = {-2,-3,-3,-1,1,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,0,1,-3,1,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#22
//Both nums1 and num2 have negative and positive digits
//with 2 or more carries of 1 & -1 which is a ripple  carry
TEST(test_m_add, TEST_22){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,3,1,-1,3,1};
  MEDUSOID_NUMBER num2 = {-2,3,1,-1,-1,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,-2,3,-2,2,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#23
//Both nums1 and num2 have negative, positive digits and zeroes
//with 2 or more carries of 1 & -1 which is a ripple  carry
TEST(test_m_add, TEST_23){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-3,3,1,-1,3,1};
  MEDUSOID_NUMBER num2 = {-2,3,1,-1,0,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,-2,3,-2,3,1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#24
//Both nums1 and num2 are all positive digits
//with 2 or more carries of 1  which is a ripple  carry
TEST(test_m_add, TEST_24){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,3,1,2,1,2};
  MEDUSOID_NUMBER num2 = {2,3,3,2,1,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,0,-2,-2,3,3};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#25
//Both nums1 and num2 have negative digits
//with 2 or more carries of 1 which is a ripple  carry
TEST(test_m_add, TEST_25){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,3,1,0,0,-2};
  MEDUSOID_NUMBER num2 = {2,3,3,2,-1,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,0,-2,3,-1,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#26
//Both nums1 and num2 are all postive and zeroes
//with 2 or more carries of 1 which is a ripple  carry
TEST(test_m_add, TEST_26){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,3,1,0,0,2};
  MEDUSOID_NUMBER num2 = {2,3,3,2,1,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,0,-2,3,1,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#27
//Both nums1 and num2 have positive and negative digits with zeroes
//with 2 or more carries of 1 which is a ripple  carry
TEST(test_m_add, TEST_27){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,3,1,1,0,0};
  MEDUSOID_NUMBER num2 = {2,3,2,1,3,-2};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,0,-3,3,3,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#28
//Both nums1 and num2 are all zeroes digits
//with no carry or ripple
TEST(test_m_add, TEST_28){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {0,0,0,0,0,0};
  MEDUSOID_NUMBER num2 = {0,0,0,0,0,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {0,0,0,0,0,0};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#29
//Both nums1 and num2 are positive and negative digits
//with no carry or ripple
TEST(test_m_add, TEST_29){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {3,-1,2,3,-3,1};
  MEDUSOID_NUMBER num2 = {-2,3,1,-3,2,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {1,2,3,0,-1,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}

//#30
//Both nums1 and num2 are all positive digits
//with no carry or ripple
TEST(test_m_add, TEST_30){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {1,1,1,1,1,1};
  MEDUSOID_NUMBER num2 = {1,1,1,1,1,1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {2,2,2,2,2,2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));
}


//#31
//Both nums1 and num2 are all negative digits
//with no carry or ripple
TEST(test_m_add, TEST_31){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-1,-2,-1,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-1,-1,-1,-2,-2,-1};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,-3,-2,-3,-3,-2};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}


//#32
//Both nums1 and num2 are all positive, negative digits and zeroes
//with no carry or ripple
TEST(test_m_add, TEST_32){
  
  int age = 3;
  MEDUSOID_NUMBER num1 = {-1,-2,0,-1,-1,-1};
  MEDUSOID_NUMBER num2 = {-1,-1,-1,-2,-2,0};

  MEDUSOID_NUMBER result;
  
  bool debug = false;
  
  MEDUSOID_NUMBER expected_result = {-2,-3,-1,-3,-3,-1};
    
  add(age,debug,num1,num2,result);
  
  ASSERT_TRUE(compare(result, expected_result));

}
