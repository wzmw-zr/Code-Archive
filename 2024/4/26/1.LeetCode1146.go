package main

import "fmt"


type SnapshotArray struct {
  Array []int
  Snapshots map[int][]int
  SnapshotCount int
}


func Constructor(length int) SnapshotArray {
  var s SnapshotArray
  s.Array = make([]int, length)
  s.Snapshots = make(map[int][]int)
  s.SnapshotCount = 0
  return s
}


func (this *SnapshotArray) Set(index int, val int)  {
  this.Array[index] = val
}


func (this *SnapshotArray) Snap() int {
  var snap_id int = this.SnapshotCount
  var snapshot []int = make([]int, len(this.Array))
  copy(snapshot, this.Array)
  this.Snapshots[snap_id] = snapshot
  this.SnapshotCount++
  return snap_id
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
  res := this.Snapshots[snap_id][index]
  return res
}

func main() {
  obj := Constructor(3)
  obj.Set(0, 5)
  fmt.Println(obj.Snap())
  obj.Set(0, 6)
  val := obj.Get(0, 0)
  fmt.Println(val)
}
