#include <unistd.h>

#include "ha-test.h"


static void
test1 (void)
{
   __attribute__((unused)) ha_node_t *r1, *r2, *r3, *a1;
   ha_replica_set_t *replica_set;

   replica_set = ha_replica_set_new("test1");
   r1 = ha_replica_set_add_replica(replica_set, "replica1");
   r2 = ha_replica_set_add_replica(replica_set, "replica2");
   r3 = ha_replica_set_add_replica(replica_set, "replica3");
   a1 = ha_replica_set_add_arbiter(replica_set, "arbiter1");

   ha_replica_set_start(replica_set);
   ha_replica_set_wait_for_healthy(replica_set);
   ha_replica_set_shutdown(replica_set);
   ha_replica_set_destroy(replica_set);
}


int
main (int argc,
      char *argv[])
{
   test1();

   return 0;
}
