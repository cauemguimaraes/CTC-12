if(EXISTS "/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12 LAB/lab3/labsort/build/labSorttests[1]_tests.cmake")
  include("/mnt/c/Users/cauem/OneDrive/Área de Trabalho/ITA/ITA 5S/CTC_12 LAB/lab3/labsort/build/labSorttests[1]_tests.cmake")
else()
  add_test(labSorttests_NOT_BUILT labSorttests_NOT_BUILT)
endif()
