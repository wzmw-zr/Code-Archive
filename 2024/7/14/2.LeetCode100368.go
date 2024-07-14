package main

import (
  "fmt"
)

/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
 type ListNode struct {
    Val int
    Next *ListNode
 }

 func reverse(head *ListNode) *ListNode {
  tmp := &ListNode{}
  for head != nil {
    next := head.Next
    head.Next = tmp.Next
    tmp.Next = head
    head = next
  }
  return tmp.Next
 }

func modifiedList(nums []int, head *ListNode) *ListNode {
  tmp := &ListNode{}
  mp := make(map[int]int)
  for _, x := range nums {
    mp[x] = 1
  }
  for head != nil {
    next := head.Next
    if _, ok := mp[head.Val]; !ok {
      head.Next = tmp.Next
      tmp.Next = head
    }
    head = next
  }
  return reverse(tmp.Next)
}
