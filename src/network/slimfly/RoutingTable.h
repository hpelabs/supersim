/*
 * Copyright 2016 Hewlett Packard Enterprise Development LP
 *
 * Licensed under the Apache License, Version 2.0 (the 'License');
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */
#ifndef NETWORK_SLIMFLY_ROUTINGTABLE_H_
#define NETWORK_SLIMFLY_ROUTINGTABLE_H_

#include <prim/prim.h>
#include <vector>
#include <string>
#include <unordered_map>

namespace SlimFly {

class RoutingTable {
 public:
  explicit RoutingTable(const std::vector<u32>& _srcAddr);

  void addHop(u32 srcPort, const std::vector<u32>& dstAddr);
  void addPath(
    const std::vector<u32>& dstAddr, const std::vector<u32>& thruAddr);

  inline const std::vector<u32>& getAddr() const {
    return srcAddr_;
  }
  u32 getNumHops(const std::vector<u32>& dstAddr) const;
  u32 getOutPort(const std::vector<u32>& dstAddr) const;

 private:
  typedef std::unordered_map<std::string, u32> PathMap;

  const std::vector<u32> srcAddr_;
  PathMap hopTable_;
  PathMap pathTable_;
};

}  // namespace SlimFly
#endif  // NETWORK_SLIMFLY_ROUTINGTABLE_H_
