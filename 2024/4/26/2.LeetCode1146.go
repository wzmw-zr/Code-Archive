package main

import "fmt"

type SnapshotArray struct {
  Snapshots []map[int]int
  SnapshotTimes [][]int
  SnapshotID int
}


func Constructor(length int) SnapshotArray {
  var s SnapshotArray
  s.Snapshots = make([]map[int]int, length)
  for i := 0; i < length; i++ {
    s.Snapshots[i] = make(map[int]int)
    s.Snapshots[i][0] = 0
  }
  s.SnapshotTimes = make([][]int, length)
  for i := 0; i < length; i++ {
    s.SnapshotTimes[i] = make([]int, 1)
  }
  s.SnapshotID = 0
  return s
}


func (this *SnapshotArray) Set(index int, val int)  {
  var snap_id int = this.SnapshotID
  this.Snapshots[index][snap_id] = val
  var length = len(this.SnapshotTimes[index])
  if snap_id != this.SnapshotTimes[index][length - 1] {
    this.SnapshotTimes[index] = append(this.SnapshotTimes[index], snap_id)
  }
}


func (this *SnapshotArray) Snap() int {
  var snap_id int = this.SnapshotID
  this.SnapshotID++
  return snap_id
}


func (this *SnapshotArray) Get(index int, snap_id int) int {
  ans, ok := this.Snapshots[index][snap_id]
  if ok {
    return ans
  }
  var l, r int
  r = len(this.SnapshotTimes[index]) - 1
  for l < r {
    var mid int = (l + r + 1) / 2
    if this.SnapshotTimes[index][mid] < snap_id {
      l = mid
    } else {
      r = mid - 1
    }
  }
  snap_id = this.SnapshotTimes[index][l]
  return this.Snapshots[index][snap_id]
}


func main() {
  obj := Constructor(1)
  obj.Set(0, 15)
  fmt.Println(obj.Snap())
  fmt.Println(obj.Snap())
  fmt.Println(obj.Snap())
  fmt.Println(obj.Get(0, 2))
  fmt.Println(obj.Snap())
  fmt.Println(obj.Snap())
  fmt.Println(obj.Get(0, 0))
}
