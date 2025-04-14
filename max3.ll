; ModuleID = "max3_module"
target triple = "x86_64-unknown-linux-gnu"
target datalayout = ""

define i64 @"max3"(i64 %"a", i64 %"b", i64 %"c")
{
entry:
  %".5" = icmp sgt i64 %"a", %"b"
  %".6" = select  i1 %".5", i64 %"a", i64 %"b"
  %".7" = icmp sgt i64 %".6", %"c"
  %".8" = select  i1 %".7", i64 %".6", i64 %"c"
  ret i64 %".8"
}
