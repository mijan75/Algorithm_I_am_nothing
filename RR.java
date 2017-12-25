int timing = 0;

        while (true){
            boolean done = true;

            for(int i=0; i<tempModelList.size(); i++){
                int remainingTime = tempModelList.get(i).getBurstTime();
                int anotherTime = models.get(i).getBurstTime();

                if(remainingTime > 0){
                    done = false;
                    if(remainingTime > quantumTime){
                        timing = timing + quantumTime;
                        int remTime = remainingTime - quantumTime;
                        tempModelList.get(i).setBurstTime(remTime);
                    }

                    else{
                        timing = timing + remainingTime;
                        anotherTime = timing - anotherTime;
                        models.get(i).setWaitngTime(anotherTime);
                        tempModelList.get(i).setBurstTime(0);
                    }
                }

            }
            if(done)
                break;
        }
        double averageWatingtime = 0;
        double turnAroundTime = 0;

        for(int i=0; i<models.size(); i++){
            averageWatingtime += models.get(i).getWaitngTime();
            turnAroundTime += models.get(i).getWaitngTime() + models.get(i).getBurstTime();
        }
        System.out.println(averageWatingtime/models.size()+" "+turnAroundTime/models.size());
